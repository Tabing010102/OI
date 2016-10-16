#include <cstdio>
using namespace std;
const int maxn = 100+5;
const int INF = 0x7fffffff;
FILE *fin, *fout;
int n;
int steps[maxn];
bool G[maxn][maxn], vis[maxn];
int best_step = INF;
int ans[10000][maxn], ans_c=0;
bool check() {
	for(int i = 1; i <= n; i++) if(!vis[i]) return false;
	return true;
}
void dfs(int last, int cnt_step) {
	if(cnt_step-1 > best_step) return;
	if(check()) {
		if(best_step == cnt_step-1) {
			ans_c++;
			for(int i = 0; i <= cnt_step-1; i++) ans[ans_c][i] = steps[i];
		} else {
			ans_c = 1;
			best_step = cnt_step-1;
			for(int i = 0; i <= cnt_step-1; i++) ans[ans_c][i] = steps[i];
		}
		return;
	}
//	for(int i = 1; i <= n; i++) if(!vis[i]) {
//last???? 
	for(int i = last+1; i <= n; i++) {
		int yvis[maxn];
		for(int j = 1; j <= n; j++) yvis[j] = vis[j];
		steps[cnt_step] = i;
		vis[i] = true;
		int nn1=0, nn2=0;
		for(int j = 1; j <= n; j++) if(G[i][j]) {
			nn1++;
			if(!vis[j]) nn2++;
			vis[j] = true;
		}
		
//		fprintf(fout, "cnt_step=%d, After adding i=%d,\nvis:", cnt_step, i);
//		for(int j = 1; j <= n; j++) fprintf(fout, "%d ", vis[j]);
//		fprintf(fout, "\n");
		
		if(nn1-nn2 > 0) dfs(i, cnt_step+1);
		for(int j = 1; j <= n; j++) vis[j] = yvis[j];
		
//		fprintf(fout, "When all is done\nvis:");
//		for(int j = 1; j <= n; j++) fprintf(fout, "%d ", vis[j]);
//		fprintf(fout, "\n");

	}
}
int main() {
	fin = fopen("zpj.in", "r");
	fout = fopen("zpj.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int t;
			fscanf(fin, "%d", &t);
			G[i][j] = t?true:false;
		}
		G[i][i] = true;
	}
	
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) fprintf(fout, "%d ", G[i][j]);
//		fprintf(fout, "\n");
//	}

	dfs(0, 1);
	fprintf(fout, "%d\n%d\n", best_step, ans_c);
	for(int i = 1; i <= ans_c; i++) {
		for(int j = 1; j <= best_step; j++) fprintf(fout, "%d ", ans[i][j]);
		fprintf(fout, "\n");
	}
	return 0;
}
