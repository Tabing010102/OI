#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
FILE *fin, *fout;
struct Edge {
	int from ,to, cap, flow;
	Edge(int a, int b, int c, int d) {
		this->from = a;
		this->to = b;
		this->cap = c;
		this->flow = d;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int a[maxn];//从起点的可改进量 
int p[maxn];//最短路的上一条弧 
int n;
void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int m = edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}
inline int min(int a, int b) { return a<b?a:b; }
int EK(int s, int t) {
	int flow = 0;
	while(1) {
		memset(a, 0, sizeof(a));
		queue<int> q;
		q.push(s);
		a[s] = INF;
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i = 0; i < G[x].size(); i++) {
				Edge &e = edges[G[x][i]];
				if(!a[e.to] && e.cap>e.flow) {
					p[e.to] = G[x][i];
					a[e.to] = min(a[x], e.cap-e.flow);
					q.push(e.to);
				}
			}
			if(a[t]) break;
		}
		if(!a[t]) break;
		for(int u = t; u != s; u = edges[p[u]].from) {
			edges[p[u]].flow += a[t];
			edges[p[u]^1].flow -= a[t];
		}
		flow += a[t];
	}
	return flow;
}
int main() {
	fin = fopen("maxflowa.in", "r");
	fout = fopen("maxflowa.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	edges.clear();
	for(int i = 1; i <= n; i++) G[i].clear();
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
		int tmp;
		fscanf(fin, "%d", &tmp);
		if(tmp) AddEdge(i, j, tmp);
	}
	fprintf(fout, "%d\n", EK(1, n));
	return 0;
}
