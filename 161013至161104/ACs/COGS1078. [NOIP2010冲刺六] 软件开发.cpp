#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100+5;
FILE *fin, *fout;
int n, m, d[maxn][2], ans;
int f[maxn][maxn];//f[i][j]表示前i个人，作j个a，最多作几个b 
//f[i][j] = max(f[i-1][j-k] + (tl-k*d1)/d2)     k=min(m/d1, j)
inline int max(int a, int b) { return a<b?b:a; }
inline int min(int a, int b) { return a<b?a:b; }
bool dp(int tl) {
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= min(tl/d[i][0], j); k++) 
			if(f[i-1][j-k] != -1) {
				int tmp = (tl-k*d[i][0]) / d[i][1];
				f[i][j] = max(f[i][j], f[i-1][j-k] + tmp);
			}
	if(f[n][m] >= m) return true;
	else return false;
}
int main() {
	fin = fopen("time.in", "r");
	fout = fopen("time.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		fscanf(fin, "%d%d", &d[i][0], &d[i][1]);
	int l=0, r=20000, m;
	while(l <= r) {
		m = l + (r-l)/2;
		if(dp(m)) { r = m-1; ans = m; }
		else l = m+1;
	}
	fprintf(fout, "%d\n", ans);
	return 0;
}
