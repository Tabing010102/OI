#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using std::vector;
using std::next_permutation;
using std::prev_permutation;
using std::sort;

struct Node {
	int d[10];
	bool operator< (const Node &rhs) const {
		for(int i = 0; i < 10; i++)
			if(this->d[i] < rhs.d[i])
				return true;
		return false;
	}
	Node(int *n) {
		for(int i = 0; i < 10; i++) this->d[i] = n[i];
	}
	Node(const Node &rhs) {
		for(int i = 0; i < 10; i++) this->d[i] = rhs.d[i];
	}
};

int n, ans=0, d[10];
vector<Node> ansv;

void dfs(int dep, int last, int left) {
	if(left == 0) {
		//ans++;
		ansv.push_back(Node(d));
		int t[10], *tc=ansv[ansv.size()-1].d;
		for(int i = 0; i < 10; i++) t[i] = tc[i];
		for(int i = 0; i < 10; i++) t[i]++;
		ansv.pop_back();
		do {
			//printf("dfs: "); for(int i = 0; i < 10; i++) printf("%d ", t[i]); printf("\n");
			ansv.push_back(Node(t));
			ans++;
		} while(prev_permutation(t, t+10));
		return;
	}
	if(left < 0) return;
	if(dep == 10) {
		if(last != 0) return;
		else {
			//ans++;
			ansv.push_back(Node(d));
			int t[10], *tc=ansv[ansv.size()-1].d;
			for(int i = 0; i < 10; i++) t[i] = tc[i];
			for(int i = 0; i < 10; i++) t[i]++;
			ansv.pop_back();
			do {
				//printf("dfs: "); for(int i = 0; i < 10; i++) printf("%d ", t[i]); printf("\n");
				ansv.push_back(Node(t));
				ans++;
			} while(prev_permutation(t, t+10));
		}
	}
	for(int i = last; i >= 1; i--) {
		d[dep] = i;
		dfs(dep+1, i, left-i);
	}
}

int main() {
	scanf("%d", &n);
	if(n<10 || n>30) { printf("0\n"); return 0; }
	n -= 10;
	dfs(0, 2, n);
	printf("%d\n", ans);
	sort(ansv.begin(), ansv.end());
	//printf("ansv.size = %d\n", ansv.size());
	//printf("sizof(ansv) = %d\n", sizeof(ansv));
	for(int i = 0; i < ans; i++) {
		for(int j = 0; j < 10; j++)
			printf("%d ", ansv[i].d[j]);
		printf("\n");
	}
	return 0;
}
