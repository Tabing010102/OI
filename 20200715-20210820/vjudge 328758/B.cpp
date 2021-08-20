#include <cstdio>
#include <cstring>

const int maxn = 100+10;
const int detla[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},
						  {0, -1},         {0, 1},
						  {1, -1}, {1, 0}, {1, 1} };

int n, m, ans=0;
char buf[maxn];
bool G[maxn][maxn];
bool vis[maxn][maxn];

void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++) {
		int tx=x+detla[i][0], ty=y+detla[i][1];
		if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
		if(!G[tx][ty] || vis[tx][ty]) continue;
		dfs(tx, ty);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", buf);
		for(int j = 0; j < m; j++) G[i][j] = buf[j]=='W'?1:0;
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		if(G[i][j] && !vis[i][j]) { dfs(i, j); ans++; }
	printf("%d\n", ans);
	return 0;
}
