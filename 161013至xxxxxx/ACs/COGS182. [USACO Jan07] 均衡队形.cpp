#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 50000+100;
FILE *fin, *fout;
int n, q, A[maxn], d[2][maxn][17];//0最小值,1最大值 
int min(int a, int b) { return a<b?a:b; }
int max(int a, int b) { return a<b?b:a; }
void RMQ_init(int n) {
	for(int i = 0; i < n; i++) d[0][i][0] = d[1][i][0] = A[i];
	for(int j = 1; (1<<j) <= n; j++) 
		for(int i = 0; i+(1<<j)-1 < n; i++) {
			d[0][i][j] = min(d[0][i][j-1], d[0][i+(1<<(j-1))][j-1]);
			d[1][i][j] = max(d[1][i][j-1], d[1][i+(1<<(j-1))][j-1]);
		}
}
int RMQ(int L, int R) {
	int k = 0;
	while(1<<(k+1) <= R-L+1) k++;
	return max(d[1][L][k], d[1][R-(1<<k)+1][k]) - min(d[0][L][k], d[0][R-(1<<k)+1][k]);
}
int main() {
	fin = fopen("lineup.in", "r");
	fout = fopen("lineup.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		fscanf(fin, "%d", &A[i]);
	RMQ_init(n);
	for(int i = 1; i <= q; i++) {
		int L, R;
		fscanf(fin, "%d%d", &L, &R);
		fprintf(fout, "%d\n", RMQ(L-1, R-1));
	}
	return 0;
}
