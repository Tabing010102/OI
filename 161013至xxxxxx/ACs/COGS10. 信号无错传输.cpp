#include <cstdio>
using namespace std;
const int maxn = 100+5;
FILE *fin, *fout;
int n, G[maxn][maxn];
bool vis[maxn];
int best=0, ans[10000][maxn], ans_cc=1;
void dfs(int now, int cc) {
	if(best > cc+n-now+1) return;
	if(now == n+1) {
		if(cc > best) {
			best = cc;
			ans_cc = 1;
			int tmp = 1;
			for(int i = 1; i <= n; i++) if(vis[i]) ans[ans_cc][tmp++] = i;
		} else if(cc == best) {
			ans_cc++;
			int tmp = 1;
			for(int i = 1; i <= n; i++) if(vis[i]) ans[ans_cc][tmp++] = i;
		} else;
	} else {
		bool flag = true;
		for(int i = 1; i < now; i++) if(vis[i]) 
		if(G[i][now]) { flag = false; break; }
		if(flag) {
			vis[now] = true;
			dfs(now+1, cc+1);
			vis[now] = false;
		}
		dfs(now+1, cc);
	}
}
int main() {
	fin = fopen("dlj.in", "r");
	fout = fopen("dlj.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
		fscanf(fin, "%d", &G[i][j]);
	dfs(1, 0);
	fprintf(fout, "%d\n%d\n", best, ans_cc);
	for(int i = 1; i <= ans_cc; i++) {
		for(int j = 1; j <= best; j++) fprintf(fout, "%d ", ans[i][j]);
		fprintf(fout, "\n");
	}
	return 0;
}
