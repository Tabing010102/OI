/*
��ά 
״̬���壺f[i][j]��ʾ��1~i������Ʒװ�뱳��,ʣ��j�Ŀռ� 
״̬ת�Ʒ��̣�f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]); 1<=i<=n,0<=j<=m
�𰸣�max(f[n][k], 0<=k<=n) 
һά
״̬���壺f[i]��ʣ��i�ռ䣨�������飩
״̬ת�Ʒ��̣�f[j] = max(f[j], f[j-w[i]]+v[i]) 0<=j<=m
�𰸣�max(f[k], 0<=k<=m) 
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
