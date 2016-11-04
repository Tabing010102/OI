#include <cstdio>
using namespace std;
const int maxn = 100000+10;
FILE *fin, *fout;
int n, A[maxn], m;
int lowbit(int x) { return x&-x; }
void add(int k, int d) {
	while(k <= n) {
		A[k] += d;
		k += lowbit(k);
	}
}
int sum(int k) {
	int ans = 0;
	while(k > 0) {
		ans += A[k];
		k -= lowbit(k);
	}
	return ans;
}
int main() {
	fin = fopen("shulie.in", "r");
	fout = fopen("shulie.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		int t;
		fscanf(fin, "%d", &t);
		add(i, t);
	}
	fscanf(fin, "%d", &m);
	int o1, o2;
	for(int i = 1; i <= m; i++) {
		char buf[20];
		fscanf(fin, "%s", buf);
		if(buf[0] == 'S') {
			fscanf(fin, "%d%d", &o1, &o2);
			fprintf(fout, "%d\n", sum(o2)-sum(o1-1));
		} else {
			fscanf(fin, "%d%d", &o1, &o2);
			add(o1, o2);
		}
	}
	return 0;
}
