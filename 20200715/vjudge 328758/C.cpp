#include <cstdio>
#include <cstring>

const int maxn = 8+2;

int n, k, ans;
bool G[maxn][maxn];
char buf[maxn];
bool visy[maxn];

void dfs(int dep, int cnt) {
	if(cnt == k) { ans++; return; }
	if(dep == n) return;
	for(int i = 0; i < n; i++) if(G[dep][i]) {
		if(visy[i]) continue;
		visy[i] = 1;
		dfs(dep+1, cnt+1);
		visy[i] = 0;
	}
	dfs(dep+1, cnt);
}

int main() {
	while(scanf("%d%d", &n, &k)==2 && n>0 &&k>0 ) {
		for(int i = 0; i < n; i++) {
			scanf("%s", buf);
			for(int j = 0; j < n; j++) G[i][j] = buf[j]=='#'?1:0;
		}
		ans = 0;
		memset(visy, 0, sizeof(visy));
		//for(int i = 0; i <= n-k; i++) dfs(i, 0);
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
