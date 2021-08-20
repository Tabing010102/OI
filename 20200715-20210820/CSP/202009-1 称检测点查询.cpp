#include <cstdio>
#include <queue>
#include <cmath>

const int maxn = 200+10;
const double eps = 1e-5;

double abs(double a) { return a<0?-a:a; }

struct Node {
	int id;
	double dist;
	Node(int id, double dist):id(id), dist(dist) {};
	bool operator < (const Node &rhs) const {
		if(abs(dist-rhs.dist) < eps) return id>rhs.id;
		else return dist > rhs.dist;
	}
};

std::priority_queue<Node> pq;
int n, x, y;

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++) {
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		double dist = sqrt((tx-x)*(tx-x) + (ty-y)*(ty-y));
		pq.push(Node(i, dist));
	}
	for(int i = 0; i < 3; i++) {
		Node x = pq.top(); pq.pop();
		printf("%d\n", x.id);
	}
	return 0;
}
