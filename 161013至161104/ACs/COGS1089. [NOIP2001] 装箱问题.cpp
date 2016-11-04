/*
状态定义：f[i]为剩余容量为i是装的最多的
状态转移方程：f[j] = max(f[j], f[j-w[i]]+v[i])
答案：f[c]
*/
#include <cstdio>
using namespace std;
const int maxn = 30+5;
const int maxc = 20000+10;
FILE *fin, *fout;
int c, n, w[maxn], v[maxn], f[maxc];
inline int max(int a, int b) { return a < b ? b : a; } 
int main() {
	fin = fopen("npack.in", "r");
	fout = fopen("npack.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &c, &n);
	for(int i = 1; i <= n; i++) {
		int a;
		fscanf(fin, "%d", &a);
		w[i] = v[i] = a;
	}
	for(int i = 1; i <= n; i++)
		for(int j = c; j >= 0; j--)
			if(j >= w[i]) f[j] = max(f[j], f[j-w[i]]+v[i]);
	fprintf(fout, "%d", c-f[c]);
	return 0;
}
