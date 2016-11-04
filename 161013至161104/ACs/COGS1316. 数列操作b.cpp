#include <cstdio>
using namespace std;
const int maxn = 100000+10;
FILE *fin, *fout;
int n, m;
int A[maxn];
int lowbit(int x) { return x&-x; }
void add(int p, int v) {
	while(p <= n) {
		A[p] += v;
		p += lowbit(p);
	}
}
int sum(int p) {
	int ans = 0;
	while(p > 0) {
		ans += A[p];
		p -= lowbit(p);
	}
	return ans;
}
int main() {
	fin = fopen("shulieb.in", "r");
	fout = fopen("shulieb.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	int last=0;
	for(int i = 1; i <= n; i++) {
		int t;
		fscanf(fin, "%d", &t);
		int av = t-last;
		last = t;
		add(i, av);
	}
	fscanf(fin, "%d", &m);
	for(int i = 1; i <= m ;i++) {
		char buf[20];
		fscanf(fin, "%s", buf);
		if(buf[0] == 'Q') {
			int o1;
			fscanf(fin, "%d", &o1);
			fprintf(fout, "%d\n", sum(o1));
		} else {
			int o1, o2, o3;
			fscanf(fin, "%d%d%d", &o1, &o2, &o3);
			add(o1, o3); add(o2+1, -o3);
		}
	}
	return 0;
}
