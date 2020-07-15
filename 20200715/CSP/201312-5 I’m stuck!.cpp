//#-1, +1, -2, |3, .4, S5, T6
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using std::queue;

const int maxn = 50+10;
const int dx1[] = { -1, 0, 0, 1 };
const int dy1[] = { 0, -1, 1, 0 };
const int dx2[] = { 0, 0 };
const int dy2[] = { -1, 1 };
const int dx3[] = { -1, 1 };
const int dy3[] = { 0, 0 };
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

struct Node {
	int x, y, type;
	Node(int a=0, int b=0, int c=0): x(a), y(b), type(c) {};
};

int n, m, G[maxn][maxn], ans=0;
char buf[maxn];
queue<Node> q;
bool vis[maxn][maxn], svis[maxn][maxn], evis[maxn][maxn];
bool inq[maxn][maxn];
Node st, end;

int get(char c) {
	if(c == '#') return -1;
	else if(c == '+') return 1;
	else if(c == '-') return 2;
	else if(c == '|') return 3;
	else if(c == '.') return 4;
	else if(c == 'S') return 5;
	else if(c == 'T') return 6;
	else return 0;
}

void rprocess(Node &x) {
	for(int i = 0; i < 4; i++) {
		int tx=x.x+dx1[i], ty=x.y+dy1[i];
		if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
		if(inq[tx][ty]) continue;
		if(G[tx][ty]==1 || G[tx][ty]==5) {
			vis[tx][ty] = 1; inq[tx][ty] = 1;
			q.push(Node(tx, ty, G[tx][ty]));
		} else if(G[tx][ty] == 2) {
			if(i==1 || i==2) {
				vis[tx][ty] = 1; inq[tx][ty] = 1;
				q.push(Node(tx, ty, G[tx][ty]));
			}
		} else if(G[tx][ty] == 3) {
			if(i==0 || i==3) {
				vis[tx][ty] = 1; inq[tx][ty] = 1;
				q.push(Node(tx, ty, G[tx][ty]));
			}
		} else if(G[tx][ty] == 4) {
			if(i == 0) {
				vis[tx][ty] = 1; inq[tx][ty] = 1;
				q.push(Node(tx, ty, G[tx][ty]));
			}
		} else continue;
	}
}

void process(Node &x) {
	if(x.type==1 || x.type==5 || x.type==6) {
		for(int i = 0; i < 4; i++) {
			int tx=x.x+dx1[i], ty=x.y+dy1[i];
			if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
			if(G[tx][ty] == -1) continue;
			if(inq[tx][ty]) continue;
			vis[tx][ty] = 1; inq[tx][ty] = 1;
			q.push(Node(tx, ty, G[tx][ty]));
		}
	} else if(x.type == 2) {
		for(int i = 0; i < 2; i++) {
			int tx=x.x+dx2[i], ty=x.y+dy2[i];
			if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
			if(G[tx][ty] == -1) continue;
			if(inq[tx][ty]) continue;
			vis[tx][ty] = 1; inq[tx][ty] = 1;
			q.push(Node(tx, ty, G[tx][ty]));
		}
	} else if(x.type == 3) {
		for(int i = 0; i < 2; i++) {
			int tx=x.x+dx3[i], ty=x.y+dy3[i];
			if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
			if(G[tx][ty] == -1) continue;
			if(inq[tx][ty]) continue;
			vis[tx][ty] = 1; inq[tx][ty] = 1;
			q.push(Node(tx, ty, G[tx][ty]));
		}
	} else if(x.type == 4) {
		int tx=x.x+1, ty=x.y;
		if(tx<0 || tx>=n || ty<0 || ty>=m) return;
		if(G[tx][ty] == -1) return;
		if(inq[tx][ty]) return;
		vis[tx][ty] = 1; inq[tx][ty] = 1;
		q.push(Node(tx, ty, G[tx][ty]));
	} else;
}

void print_vis() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) printf("%d ", vis[i][j]);
		printf("\n");
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", buf);
		for(int j = 0; j < m; j++) {
			G[i][j] = get(buf[j]);
			if(G[i][j] == 5) { st = Node(i, j, 1); G[i][j] = 1; }
			if(G[i][j] == 6) { end = Node(i, j, 1); G[i][j] = 1; }
		}
	}
	inq[st.x][st.y] = 1; vis[st.x][st.y] = 1; q.push(st);
	while(!q.empty()) {
		Node x = q.front(); q.pop();
		printf("p(%d, %d)t%d\n", x.x, x.y, x.type);
		process(x);
		print_vis();
	}
	if(!vis[end.x][end.y]) { printf("I'm stuck!\n"); exit(0); }
	printf("st: \n");
	print_vis();
	memcpy(svis, vis, sizeof(vis));
	memset(vis, 0, sizeof(vis));
	memset(inq, 0, sizeof(inq));
	inq[end.x][end.y] = 1; vis[end.x][end.y] = 1; q.push(end);
	//printf("before end: \n");
	//print_vis();
	while(!q.empty()) {
		Node x = q.front(); q.pop();
		//printf("rp(%d, %d)t%d\n", x.x, x.y, x.type);
		rprocess(x);
	}
	printf("after end: \n");
	print_vis();
	memcpy(evis, vis, sizeof(vis));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		if(G[i][j]>=1 && G[i][j]<=4)
			if(svis[i][j] && !evis[i][j])
				ans++;
	printf("%d\n", ans);
	return 0;
}
