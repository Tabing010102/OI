#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
FILE *fin, *fout;
int n, G[maxn][maxn], num[maxn];
bool vis[maxn], sel[maxn];
int ans[10001][maxn], ans_cc=1, best=INF;
int r[maxn];
bool cmp(int a, int b) {
	int tmp = 1;
	while(tmp<best && ans[a][tmp+1]==ans[b][tmp+1]) tmp++;
	return ans[a][tmp]>ans[b][tmp];
}
//ÐèÒªµ¹×ÅËÑË÷ 
void dfs(int now, int cc, int covered) {
	if(now < 0) return;
	if(cc > best) return;
	if(covered+num[now] < n) {
//		fprintf(fout, "now=%d, cc=%d, covered=%d, num[n]=%d, num[now-1]=%d, nans=%d\n", now, cc, covered, num[n], num[now-1], covered+num[n]-num[now-1]);
		return;
	}
	if(covered >= n) {
		if(cc < best) {
			best = cc;
			ans_cc = 1;
			int tmp = 1;
			for(int i = 1; i <= n; i++) if(sel[i]) ans[ans_cc][tmp++] = i;
		} else if(cc == best) {
			ans_cc++;
			int tmp = 1;
			for(int i = 1; i <= n; i++) if(sel[i]) ans[ans_cc][tmp++] = i;
		}
	} else {
		bool tmp[maxn];
		for(int i = 1; i <= n; i++) tmp[i] = vis[i];
		int chc = 0;
		for(int i = 1; i <= n; i++) if(G[now][i] && !vis[i]) { vis[i] = true; chc++; }
//		if(chc != 1) fprintf(fout, "now=%d, cc=%d, covered=%d, chc=%d\n", now, cc, covered, chc);
		sel[now] = true;
//		fprintf(fout, "now=%d, cc=%d, covered=%d, chc=%d\n",now, cc, covered, chc);
		dfs(now-1, cc+1, covered+chc);
		for(int i = 1; i <= n; i++) vis[i] = tmp[i];
		sel[now] = false;
		dfs(now-1, cc, covered);
	}
}
int main() {
	fin = fopen("zpj.in", "r");
	fout = fopen("zpj.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		fscanf(fin, "%d", &G[i][j]);
		if(G[i][j]) num[i]++;
	}
	for(int i = 1; i <= n; i++) G[i][i] = 1;
	for(int i = 1; i <= n; i++) num[i]++;
	for(int i = 2; i <= n; i++) num[i] += num[i-1];
	num[n+2] = num[n+1] = num[n];
//	for(int i = 1; i <= n; i++) fprintf(fout, "%d ", num[i]); fprintf(fout, "\n");
	dfs(n, 0, 0);
	for(int i = 1; i <= ans_cc; i++) r[i] = i;
	sort(r+1, r+1+ans_cc, cmp);
	fprintf(fout, "%d\n%d\n", best, ans_cc);
	for(int i = ans_cc; i >= 1; i--) {
		for(int j = 1; j <= best; j++) fprintf(fout, "%d ", ans[r[i]][j]);
		fprintf(fout, "\n");
	}
	return 0;
}
