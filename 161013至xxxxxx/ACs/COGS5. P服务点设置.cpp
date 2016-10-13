#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
const int INF = 0x7FFFFF;
int G[maxn][maxn], n, m, p;
int tmp[maxn], ans[maxn], best=INF;
//bool vis[maxn];
FILE *fin, *fout;
inline int min(int a, int b) { return a < b ? a : b; }
//inline int max(int a, int b) { return a < b ? b : a; }
void dfs(int dep, int last) {
	if(dep >= p) {
		int tot = 0;
		for(int i = 0; i < n; i++) {//枚举每个点 
			int now = INF;
			for(int j = 0; j < p; j++) 
				now = min(G[tmp[j]][i], now);
			if(tot < now) tot = now;
			if(tot >= best) return;
		}
		if(best > tot) {
			best = tot;
			for(int i = 0; i < dep; i++) ans[i] = tmp[i];
		}
		/*
		for(int i = 1; i <= p; i++) fprintf(fout, "%d ", ans[i]);
		fprintf(fout, "tot=%d", tot);
		fprintf(fout, "\n");
		*/
		return;
	}
	for(int i = last; i < n; i++) {
		tmp[dep] = i;
		dfs(dep+1, i+1);//细节 
	}
}
int main() {
	fin = fopen("djsc.in", "r");
	fout = fopen("djsc.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d%d", &n, &m, &p);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) G[i][j] = INF;
	for(int i = 0; i < n; i++) G[i][i] = 0;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		fscanf(fin, "%d%d%d", &a, &b, &c);
		G[a][b] = G[b][a] = c;
	}
	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
	if(G[i][j] > G[i][k] + G[k][j]) G[i][j] = G[i][k] + G[k][j];
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) fprintf(fout, "%d ", G[i][j]);
		fprintf(fout, "\n");
	}
	*/
	dfs(0, 0);
	sort(ans, ans+p);
	for(int i = 0; i < p; i++) fprintf(fout, "%d ", ans[i]);
	return 0;
}
