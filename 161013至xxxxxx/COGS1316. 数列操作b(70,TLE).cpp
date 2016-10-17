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
	fin = fopen("shulieb.in", "r");
	fout = fopen("shulieb.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		int t;
		fscanf(fin, "%d", &t);
		add(i, t);
	}
	fscanf(fin, "%d", &m);
	int o1, o2, o3;
	for(int i = 1; i <= m; i++) {
		char buf[20];
		fscanf(fin, "%s", buf);
		if(buf[0] == 'Q') {
			fscanf(fin, "%d", &o1);
			fprintf(fout, "%d\n", sum(o1)-sum(o1-1));
		} else {
			fscanf(fin, "%d%d%d", &o1, &o2, &o3);
			for(int j = o1; j <= o2; j++) add(j, o3);
		}
	}
	return 0;
}
