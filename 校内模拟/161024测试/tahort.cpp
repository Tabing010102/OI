#include <cstdio>
using namespace std;
const int maxn = 100000+100;
FILE *fin, *fout;
int n, d[maxn], ans = 0;
int main() {
	fin = fopen("tahort.in", "r");
	fout = fopen("tahort.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &d[i]);
	for(int l = 1; l <= n-1; l++) for(int r = l+1; r <= n; r++) {
		if(d[r] <= d[l]) continue;
		if(r-l+1 <= ans) continue;
		bool flag = true;
		for(int k = l+1; k <= r-1; k++)
		if(d[k]<=d[l] || d[k]>=d[r]) { flag = false; break; }
		if(flag) ans = r-l+1;
	}
	fprintf(fout, "%d\n", ans);
	return 0;
}
