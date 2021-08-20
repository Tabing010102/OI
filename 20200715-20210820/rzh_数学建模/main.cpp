#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 300;
const double INF = 1e18;

struct HeapNode {
	int u; double d;
	HeapNode(int a, double b): u(a), d(b) {};
	bool operator < (const HeapNode &rhs) const {
		return d > rhs.d;
	}
};

struct Edge {
	int from, to;
	double absdist, spd;
	double dist;
	Edge(int a, int b, double c, double d): from(a), to(b), absdist(c), spd(d) {
		dist = absdist/spd;
	};
};

int n, m, T;
vector<Edge> edges;
vector<int> G[maxn];
map<string, int> emap;
string estr[maxn];
priority_queue<HeapNode> pq;
double d[maxn];
bool done[maxn];
int p[maxn];

void AddEdge(int a, int b, double c, double d) {
	edges.push_back(Edge(a, b, c ,d));
	edges.push_back(Edge(b, a, c ,d));
	int m = edges.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}

void dijkstra(int s) {
	while(!pq.empty()) pq.pop();
	for(int i = 0; i < n; i++) d[i] = INF;
	d[s] = 0;
	memset(done, 0, sizeof(done));
	memset(p, -1, sizeof(p));
	pq.push(HeapNode(s, 0));
	while(!pq.empty()) {
		HeapNode x = pq.top(); pq.pop();
		int u = x.u;
		if(done[u]) continue;
		done[u] = true;
		for(int i = 0; i < G[u].size(); i++) {
			Edge &e = edges[G[u][i]];
			if(d[e.to] > d[u]+e.dist) {
				d[e.to] = d[u]+e.dist;
				p[e.to] = G[u][i];
				pq.push(HeapNode(e.to, d[e.to]));
			}
		}
	}
}

void print_path(int s, int cnt) {
	int priv = edges[p[cnt]].from;
	if(priv == s) cout << "->" << estr[cnt];
	else {
		print_path(s, priv);
		cout << "->" << estr[cnt];
	}
}

int main(int argc, char *argv[]) {
	cin >> n;
	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		emap[tmp] = i;
		estr[i] = tmp;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		string a, b;
		double c, d;
		cin >> a >> b >> c >> d;
		AddEdge(emap[a], emap[b], c, d);
	}
	cin >> T;
	while(T--) {
		string a, b;
		cin >> a >> b;
		int an=emap[a], bn=emap[b];
		dijkstra(an);
		cout << "Min time from " << a << " to " << b << " is: "
			 << d[bn] << " s" << endl;
		cout << "Path: " << a;
		print_path(an, bn);
		cout << endl;
	}
	return 0;
}
