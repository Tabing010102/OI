#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

//typedef long long LL;

const int maxn = 100+5;
const int INF = 0x7fffffff;
const int INF2 = 0x3f3f3f3d;

struct Edge {
	int from, to;
	//LL dist;
	int dist;
	Edge(int a, int b, int c):from(a), to(b), dist(c) {};
	Edge() {};
};

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode &rhs) const {
		return d > rhs.d;
	}
	HeapNode(int d, int u):d(d), u(u) {};
	HeapNode() {};
};

int n, m;
vector<Edge> edges;
vector<int> G[maxn];
//LL d[maxn];
int d[maxn];
int G2[maxn][maxn];

//void AddEdge(int f, int t, LL dist) {
void AddEdge(int from, int to, int dist) {
	edges.push_back(Edge(from, to, dist));
	edges.push_back(Edge(to, from, dist));
	G[from].push_back(m++);
	G[to].push_back(m++);
}

priority_queue<HeapNode> Q;

void dij(int s) {
	for(int i = 0; i < n; i++) d[i] = INF; d[s] = 0;
	Q.push(HeapNode(0, s));
	while(!Q.empty()) {
		HeapNode x = Q.top(); Q.pop();
		int u = x.u;
		if(x.d != d[u]) continue;
		for(int i = 0; i < G[u].size(); i++) {
			Edge &e = edges[G[u][i]];
			if(d[e.to] > d[u]+e.dist) {
				d[e.to] = d[u]+e.dist;
				Q.push(HeapNode(d[e.to], e.to));
			}
		}
	}
}

int run() {
	int tans = 0;
	for(int i = 0; i < n; i++) {
		dij(i);
		for(int j = i+1; j < n; j++) tans += d[j];
	}
	return tans;
}

int d2[maxn][maxn];

void floyed() {
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				//if(d2[i][j]<INF && d2[k][j]<INF)
					d2[i][j] = min(d2[i][j], d2[i][k]+d2[k][j]);
}

int run2() {
	int tans = 0;
	//for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d2[i][j] = INF;
	//for(int i = 0; i < n; i++) d2[i][i] = 0;
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) printf("%d ", d2[i][j]);
		printf("\n");
	}*/
	floyed();
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) printf("%d ", d2[i][j]);
		printf("\n");
	}*/
	for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) tans += d2[i][j];
	return tans;
}

int main() {
	scanf("%d%d", &n, &m);
	if(m*log(n)/log(2)*5 < 0) {//dij
		int t = m; m = 0;
		for(int i = 0; i < t; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			AddEdge(a-1, b-1, c);
		}
		int ans = INF;
		for(int i = 0; i < m; i+=2) {
			int t = edges[i].dist;
			G2[edges[i].from][edges[i].to] = 1;
			G2[edges[i].to][edges[i].from] = 1;
			edges[i].dist = edges[i+1].dist = 0;
			ans = min(ans, run());
			edges[i].dist = edges[i+1].dist = t;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(G2[i][j] == 0) {
					edges.push_back(Edge(i, j, 0));
					edges.push_back(Edge(j, i, 0));
					G[i].push_back(m);
					G[j].push_back(m+1);
					ans = min(ans, run());
					edges.pop_back();
					edges.pop_back();
					G[i].pop_back();
					G[j].pop_back();
					G2[i][j] = G2[j][i] = 1;
				}
		printf("%d", ans);
	} else {
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) G2[i][j] = INF2;
		for(int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			G2[a-1][b-1] = c;
			G2[b-1][a-1] = c;
		}
		//printf("8***");
		for(int i = 0; i < n; i++) G2[i][i] = 0;
		int ans = INF;
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				if(G2[i][j] > 0) {
					int t = G2[i][j];
					G2[i][j] = G2[j][i] = 0;
					for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) d2[i][j] = G2[i][j];
					ans = min(ans, run2());
					G2[i][j] = G2[j][i] = t;
				}
		printf("%d", ans);
	}
	return 0;
}
