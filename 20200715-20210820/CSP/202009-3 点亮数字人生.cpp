#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 500+10;
const int maxm = 2500+10;

struct Node {
	int func, output;
	vector<int> ine;
}nodes[maxn];
struct Edge {
	bool isin;
	int from;
	Edge() {};
	Edge(bool i, int f):isin(i), from(f) {};
};
int Q, m, n, S, dm[maxm];
vector<Edge> edges;

void process(int cnt, char buf[]) {
	int len = strlen(buf);
	int cntn=0, mp=1;
	for(int i = len-1; i >= 1; i--) {
		cntn += mp*(buf[i]-'0');
		mp *= 10;
	}
	int size = edges.size();
	if(buf[0] == 'I') edges.push_back(Edge(true, cntn));
	else edges.push_back(Edge(false, cntn));
	nodes[cnt].ine.push_back(size);
}

int main() {
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++) {
		scanf("%d%d", &m, &n);
		char func[10], buf[10];
		for(int j = 1; j <= n; j++) {
			scanf("%s", func);
			nodes[j].func = get_func(func);
			int tk; scanf("%d", &tk);
			for(int k = 0; k < tk; k++) {
				scanf("%s", buf);
				process(j, buf);
			}
		}
		scanf("%d", &S);
		for(int j = 1; j <= S; j++)
	}
	return 0;
}
