#include <cstdio>
using namespace std;
const int maxn = 350+10;
const int maxm = 40+5;
FILE *fin, *fout;
int n, m;
int w[maxn], A[5];
int f[maxm][maxm][maxm][maxm];
inline int max(int a, int b) { return a<b?b:a; }
int main() {
	fin = fopen("tortoise.in", "r");
	fout = fopen("tortoise.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d" ,&w[i]);
	for(int i = 1; i <= m; i++) {
		int t;
		fscanf(fin, "%d" ,&t);
		A[t]++;
	}
	f[0][0][0][0] = w[1];
	for(int i = 0; i <= A[1]; i++)
		for(int j = 0; j <= A[2]; j++)
			for(int k = 0; k <= A[3]; k++)
				for(int l = 0; l <= A[4]; l++) {
					if(i >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l]+w[1+i+j*2+k*3+l*4]);
					if(j >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l]+w[1+i+j*2+k*3+l*4]);
					if(k >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k-1][l]+w[1+i+j*2+k*3+l*4]);
					if(l >= 1) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l-1]+w[1+i+j*2+k*3+l*4]);
				}
	fprintf(fout, "%d\n", f[A[1]][A[2]][A[3]][A[4]]);
	return 0;
}
