/*
二维 
状态定义：f[i][j]表示把1~i个个物品装入背包,剩余j的空间 
状态转移方程：f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]); 1<=i<=n,0<=j<=m
答案：max(f[n][k], 0<=k<=n) 
一维
状态定义：f[i]表剩余i空间（滚动数组）
状态转移方程：f[j] = max(f[j], f[j-w[i]]+v[i]) 0<=j<=m
答案：max(f[k], 0<=k<=m) 
*/
#include <cstdio>
using namespace std;
const int maxn = 3402+10;
const int maxm = 12880+10;
int w[maxn], v[maxn], n, m;
//int f[maxn][maxm];
int f[maxm];
FILE *fin, *fout; 
inline int max(int a, int b) { return a < b ? b : a; }
int main() {
	fin = fopen("charm.in", "r");
	fout = fopen("charm.out", "w");
//	fin = stdin; 
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		fscanf(fin, "%d%d", &w[i], &v[i]);
	for(int i = 1; i <= n; i++) 
		for(int j = m; j >= 0; j--) {
//			f[i][j] = (i == 1 ? 0 : f[i-1][j]);
//			if(j >= w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]]+v[i]);
			if(j >= w[i]) f[j] = max(f[j], f[j-w[i]]+v[i]);
		}
//	int best = 0;
//	for(int i = 0; i <= m; i++) best = max(best, f[n][i]);
//	for(int i = 0; i <= m; i++) best = max(best, f[i]);
	fprintf(fout, "%d", f[m]);
	return 0;
}
