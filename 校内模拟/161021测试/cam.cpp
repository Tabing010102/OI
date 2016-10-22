#include <cstdio>
using namespace std;
const int maxn = 100+5;
const int maxm = 50+5;
const int maxx = 200+10;
FILE *fin, *fout;
int n, d[maxn][maxm];
//d[x][0]为第x个摄像头的位置
//d[x][1]为第x个摄像头可以照到的点的数量 
int vis[maxx];
bool is_removed[maxn];
bool ttr(int u) {
	if(is_removed[u]) return false;
	if(vis[d[u][0]] == 0) {
		is_removed[u] = true;
		for(int i = 2; i <= d[u][1]+1; i++) vis[d[u][i]]--;
		return true;
	}
	return false;
}
int main() {
	fin = fopen("cam.in", "r");
	fout = fopen("cam.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d%d", &d[i][0], &d[i][1]);
		for(int j = 1; j <= d[i][1]; j++) {
			fscanf(fin, "%d", &d[i][j+1]);
			vis[d[i][j+1]]++;
		}
	}
	bool flag = true;
	while(flag) {
		flag = false;
		for(int i = 1; i <= n; i++)
		if(ttr(i)) flag = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(!is_removed[i]) ans++;
	if(ans) fprintf(fout, "%d\n", ans);
	else fprintf(fout, "YES\n");
	return 0;
}
