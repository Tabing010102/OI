#include <cstdio>
#include <cstring>
using namespace std;
const int maxx = 1500+10;
const int INF = 0x3f3f3f3f;
FILE *fin, *fout;
int n, m, G[maxx][maxx];
struct D {
	int x, y;
}vis[maxx][maxx];
char buf[maxx];
int bx, by;
bool dfs(int xi, int yi) {
	int xx=(n+xi%n)%n, yy=(m+yi%m)%m;
	if(G[xx][yy] <= 0) return false;
	if(vis[xx][yy].x != INF) {
		if(vis[xx][yy].x!=xi || vis[xx][yy].y!=yi) return true;
		else return false;
	}
	vis[xx][yy].x=xi;
	vis[xx][yy].y=yi;
	if(dfs(xi+1, yi)) return true;
	if(dfs(xi-1, yi)) return true;
	if(dfs(xi, yi+1)) return true;
	if(dfs(xi, yi-1)) return true;
	return false;
}
int main() {
	fin = fopen("huanxiang.in", "r");
	fout = fopen("huanxiang.out", "w");
//	fout = stdout;
	while(fscanf(fin, "%d%d", &n, &m)==2 && n>0) {
		memset(vis, 0, sizeof(vis));
		memset(G, -1, sizeof(G));
		for(int i = 0; i < n; i++) {
			fscanf(fin, "%s", buf);
			for(int j = 0; j < m; j++) {
				if(buf[j] == '#') G[i][j] = 0;
				else {
					G[i][j] = 1;
					if(buf[j] == 'S') { bx = i; by = j; }
				}
				vis[i][j].x = vis[i][j].y = INF;
			}
		}
//		for(int i = 0; i < n; i++) {
//			for(int j = 0; j < m; j++) fprintf(fout, "%d", G[i][j]);
//			fprintf(fout, "\n");
//		}
		if(dfs(bx, by)) fprintf(fout, "Yes\n");
		else fprintf(fout, "No\n");
	}
	return 0;
}
