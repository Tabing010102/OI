#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100000+100;
const int INF = 0x7fffffff;
FILE *fin, *fout;
int id, n, m, q;
int in_degree[maxn], out_degree[maxn];

struct Edge {
	int from, to;
//	int dist;
	bool enabled;
	Edge(int A, int B, bool D=true) {
		this->from = A;
		this->to = B;
//		this->dist = C;
		this->enabled = D;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
void AddEdge(int from, int to) {
	edges.push_back(Edge(from, to));
	G[from].push_back(edges.size()-1);
}

struct rEdge {
	int from, to;
};
vector<rEdge> redges;
vector<int> rG[maxn];
void rAddEdge(int from, int to) {
	redges.push_back((rEdge){from, to});
	rG[from].push_back(redges.size()-1);
}

int ans = INF;
bool vis[maxn];
int A, B;
void dfs(int now, int cnt_cost) {
	if(cnt_cost > ans) return;
	if(now == B) { ans = cnt_cost; return; }
	//先把能到的遍历完再考虑把to=now的边反向
	for(int i = 0; i < G[now].size(); i++) {
		int u = G[now][i];
		if(!edges[u].enabled || vis[edges[u].to]) continue;
		vis[edges[u].to] = true;
		dfs(edges[u].to, cnt_cost);
		vis[edges[u].to] = false;
	}
	//考虑反向
	for(int i = 0; i < rG[now].size(); i++) {
		int u = rG[now][i];
		int x = redges[u].to;
		int p = 0;
		for(; ; p++) {
			int _u = G[x][p];
			if(edges[_u].to == now) break;
		}
		edges[G[x][p]].enabled = false;
		dfs(x, cnt_cost+1);
		edges[G[x][p]].enabled = true;
	}
}
int main() {
	fin = fopen("magnus.in", "r");
	fout = fopen("magnus.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &id);
	fscanf(fin, "%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++) {
		int A, B;
		fscanf(fin, "%d%d", &A, &B);
		AddEdge(A, B);
		in_degree[B]++;
		out_degree[A]++;
		rAddEdge(B, A);
	}
	for(int i = 1; i <= q; i++) {
		fscanf(fin, "%d%d", &A, &B);
//		fprintf(fout, "A=%d, B=%d\n", A, B);
		if((in_degree[A]==0 && out_degree[A]==0) ||
		   (in_degree[B]==0 && out_degree[B]==0)) {
//			fprintf(fout, "Case1: -1\n");
			fprintf(fout, "-1\n");
			continue;
		} else {
			memset(vis, 0, sizeof(vis));
			ans = INF;
			vis[A] = true;
			dfs(A, 0);
//			fprintf(fout, "Case2: %d\n", ans);
			fprintf(fout, "%d\n", ans);
		}
	}
	return 0;
}
