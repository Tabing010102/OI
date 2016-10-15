#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
const LL maxn = 10+2;
const LL INF = 1000000000000;
FILE *fin, *fout;

struct Edge {
	LL from, to, dist;
	LL needed, dist2;
	Edge(LL A, LL B, LL C, LL D, LL E) {
		this->from = A;
		this->to = B;
		this->needed = C;
		this->dist2 = D;
		this->dist = E;
	}
};
vector<Edge> edges;
vector<LL> G[maxn];
void AddEdge(LL A, LL B, LL C, LL D, LL E) {
	edges.push_back(Edge(A, B, C, D, E));
	G[A].push_back(edges.size()-1);
}

LL n, m;
bool vis[maxn], vis2[maxn][maxn];
LL ans = INF;
void dfs(LL now, LL cnt_dist) {
	if(cnt_dist > ans) return;
	if(now == n) { ans = cnt_dist; return; }
	for(LL i = 0; i < G[now].size(); i++) {
		LL u = G[now][i];
		Edge &e = edges[u];
		if(vis2[now][i]) continue;//需判断边是否被遍历过 
		vis[e.to] = true; vis2[now][i] = true;
		LL next_dist = cnt_dist;
		if(vis[e.needed]) next_dist += e.dist2;
		else next_dist += e.dist;
		dfs(e.to, next_dist);
		vis[e.to] = false; vis2[now][i] = false;
	}
}
int main() {
	fin = fopen("roads.in", "r");
	fout = fopen("roads.out", "w");
//	fout = stdout;
	fscanf(fin, "%I64d%I64d", &n, &m);
	for(LL i = 1; i <= m; i++) {
		LL a, b, c, la, lb;
		fscanf(fin, "%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &la, &lb);
		AddEdge(a, b, c, la, lb);
	}
	vis[1] = true;
	dfs(1, 0);
	if(ans >= INF) fprintf(fout, "impossible\n");
	else fprintf(fout, "%I64d\n", ans);
	return 0;
}
