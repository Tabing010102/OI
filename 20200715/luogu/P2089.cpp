#include <cstdio>
#include <vector>
#include <cstdlib>

#define FOR(x) for(d[x]=1; d[x]<=3; d[x]++)

using std::vector;

struct Node {
	int d[10];
	Node (int *n) {
		for(int i = 0; i < 10; i++) this->d[i] = n[i];
	}
};

int d[10], target;
vector<Node> ansv;

int sum(int *d) {
	int ans = 0;
	for(int i = 0; i < 10; i++) ans += d[i];
	return ans;
}

int main() {
	scanf("%d", &target);
	if(target<10 || target>30) { printf("0\n"); exit(0); }
	FOR(0) FOR(1) FOR(2) FOR(3) FOR(4) FOR(5) FOR(6) FOR(7) FOR(8) FOR(9) {
		if(sum(d) == target) {
			ansv.push_back(Node(d));
		}
	}
	printf("%d\n", ansv.size());
	for(int i = 0; i < ansv.size(); i++) {
		for(int j = 0; j < 10; j++) printf("%d ", ansv[i].d[j]);
		printf("\n");
	}
	return 0;
}
