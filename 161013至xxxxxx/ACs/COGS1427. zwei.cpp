#include <cstdio>
using namespace std;
FILE *fin, *fout;
const int maxn = 1e5+100;
int n, m, d[maxn], da[maxn];
inline int lowbit(int x) { return x&(-x); }
void add(int x, int v) {//d[x] ^= v;
	while(x <= n) {
		d[x] ^= v;
		x += lowbit(x);
	}
}
int sum(int x) {
	int ans = 0;
	while(x > 0) {
		ans ^= d[x];
		x -= lowbit(x);
	}
	return ans;
}
int main() {
	fin = fopen("zwei.in", "r");
	fout = fopen("zwei.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d", &da[i]);
		add(i, da[i]);
	}
	for(int i = 1; i <= m; i++) {
		int op, a, b;
		fscanf(fin, "%d%d%d", &op, &a, &b);
		if(op == 0) {
			add(a, da[a]^b);
			da[a] = b;
		} else {
			fprintf(fout, "%d\n", sum(b)^sum(a-1));
		}
	}
	return 0;
}
