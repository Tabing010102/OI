#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using std::queue;

const int maxn = 1000+10;
const int detla[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Node { int x, y; Node(int x=0, int y=0): x(x), y(y) {}; };

int n, m;
bool G[maxn][maxn];
int dG[maxn][maxn];
queue<Node> q;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
		int t; scanf("%d", &t);
		G[i][j] = t?true:false;
	}
	if(G[0][0]==false || G[n-1][m-1]==false) { printf("-1"); exit(0); }
	memset(dG, -1, sizeof(dG));
	q.push(Node(0, 0)); dG[0][0] = 0;
	while(!q.empty()) {
		Node cnt = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int tx = cnt.x+detla[i][0], ty = cnt.y+detla[i][1];
			if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
			if(G[tx][ty] == 0) continue;
			if(dG[tx][ty]==-1 || dG[tx][ty]>dG[cnt.x][cnt.y]+1) {
				q.push(Node(tx, ty));
				dG[tx][ty] = dG[cnt.x][cnt.y]+1;
			}
		}
	}
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) printf("%d ", dG[i][j]);
		printf("\n");
	}*/
	printf("%d", dG[n-1][m-1]);
	return 0;
}
