#include <cstdio>
using namespace std;
const int maxn = 200000+100;
const double PI = 3.14;
int n, d[maxn], T[maxn], m;
FILE *fin, *fout;
inline int lowbit(int x) { return x&(-x); }
void add(int x, int v) {//d[x] += v
	while(x <= n) {
		d[x] += v;
		x += lowbit(x);
	}
}
int sum(int x) {//Ç°xµÄºÍ
	int ans = 0;
	while(x > 0) {
		ans += d[x];
		x -= lowbit(x);
	}
	return ans;
}
int main() {
	fin = fopen("treed.in", "r");
	fout = fopen("treed.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d", &T[i]);
		add(i, T[i]);
	}
	fscanf(fin, "%d", &m);
	for(int i = 1; i <= m; i++) {
		int L, R;
		fscanf(fin, "%d%d", &L, &R);
		fprintf(fout, "%.2lf\n", PI * (sum(R)-sum(L-1)) );
		int M = L + (R-L)/2;
		add(M, -T[M]);
		T[M] = 0;
	}
	return 0;
}
