#include <cstdio>
using namespace std;
const int maxn = 1000+10;
FILE *fin, *fout;
int n, d[maxn];
int f[maxn], ftlj=0, tsn=0;
inline int max(int a, int b) { return a<b?b:a; }
int main() {
	fin = fopen("missile.in", "r");
	fout = fopen("missile.out", "w");
//	fout = stdout;
	int tmp;
	while(fscanf(fin, "%d", &tmp) == 1) { n++; d[n] = tmp; }
//	fprintf(fout, "n=%d\n", n);
	for(int i = 1; i <= n; i++) f[i] = 1;//第一问，最长不上升子序列 
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++)
			if(d[i] <= d[j]) f[i] = max(f[i], f[j]+1);
		ftlj = max(ftlj, f[i]);
	}
	fprintf(fout, "%d\n", ftlj);
	for(int i = 1; i <= n; i++) f[i] = 1;//第二问，最长上升子序列 
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < i; j++)
			if(d[i] > d[j]) f[i] = max(f[i], f[j]+1);
		tsn = max(tsn, f[i]);
	}
	fprintf(fout, "%d\n", tsn);
	return 0;
}
