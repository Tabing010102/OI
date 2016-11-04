/*
状态定义：f[x][i][j][0/1]表示分成x部分从i到j的最大(0)/小(1)值
状态转移方程：f[x][i][j][0] = max(f[x][i][j][0], f[x-1][i][k][0] * f[1][k+1][j][0])
              f[x][i][j][1] = min(f[x][i][j][1], f[x-1][i][k][1] * f[1][k+1][j][1])
答案：max(f[m][i][i+n-1][0], 1<=i<=n) 
      min(f[m][i][i+n-1][1], 1<=i<=n)
*/
#include <cstdio>
#include <climits>
using namespace std;
const int MOD = 10;
const int maxn = 50+5;
const int INF = INT_MAX;
FILE *fin, *fout;
int n, m, d[2*maxn];
int f[10][2*maxn][2*maxn][2];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a < b ? b : a; }
int main() {
	fin = fopen("numgame.in", "r");
	fout = fopen("numgame.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d", &d[i]);
		d[i+n] = d[i];
	}
	for(int i = 1; i < 2*n; i++) for(int j = i; j < 2*n; j++)	
		f[1][i][j][0] = f[1][i][j][1] = ((f[1][i][j-1][0]+d[j])%MOD + 10)%MOD;
	/*
	for(int x = 2; x <= m; x++)//初始化 
		for(int i = 1; i < 2*n; i++) for(int j = 1; j < 2*n; j++) {
			f[x][i][j][0] = 0; f[x][i][j][1] = INF;
		}
	*/
	///////////////////////////////////////////////注：-x%10 = -(x%10)////////// 
	for(int x = 2; x <= m; x++)
		for(int i = 1; i <= n; i++) for(int j = i; j < 2*n; j++)
			for(int k = i; k < j; k++) {
				f[x][i][j][0] = max(f[x][i][j][0], f[x-1][i][k][0] * f[1][k+1][j][0]);
				if(f[x][i][j][1] == 0) f[x][i][j][1] = f[x-1][i][k][1] * f[1][k+1][j][1];
	//////////////若f[x][i][j][1] == 0 ，需要转移状态，否则最小值永为0 
				else f[x][i][j][1] = min(f[x][i][j][1], f[x-1][i][k][1] * f[1][k+1][j][1]);
			}
	int _max = 0, _min = INT_MAX;
	for(int i = 1; i <= n; i++) {
		_max = max(_max, f[m][i][i+n-1][0]);
		_min = min(_min, f[m][i][i+n-1][1]);
	}
	fprintf(fout, "%d\n%d", _min, _max);
	return 0;
}
