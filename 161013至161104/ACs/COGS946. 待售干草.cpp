/*
状态定义：f[i]表示剩余i时最大装载量
状态转移方程：f[j] = max(f[j], f[j-w[i]]+v[i]);
答案：f[c] 
*/
#include <cstdio>
using namespace std;
const int maxn = 5000+10;
const int maxc = 50000+10;
int c, n, w[maxn], v[maxn], f[maxc];
FILE *fin, *fout;
inline int max(int a, int b) { return a < b ? b : a; }
int main() {
	fin = fopen("hay4sale.in", "r");
	fout = fopen("hay4sale.out" ,"w");
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
	fprintf(fout, "%d", f[c]);
	return 0;
}
