#include <cstdio>
using namespace std;
const int maxM = 100000+100;
int M, N, m[maxM], d[maxM][20];
FILE *fin, *fout;
inline int min(int a, int b) { return a<b?a:b; }
void RMQ_init(int n) {
	for(int i = 0; i < n; i++) d[i][0] = m[i];
	for(int j = 1; (1<<j) <= n; j++) 
		for(int i = 0; i+(1<<j)-1 < n; i++)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int RMQ(int L, int R) {
	int k = 0;
	while((1<<(k+1)) <= R-L+1) k++;
	return min(d[L][k], d[R-(1<<k)+1][k]);
}
int main() {
	fin = fopen("faithful.in", "r");
	fout = fopen("faithful.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &M, &N);
	for(int i = 0; i < M; i++) fscanf(fin, "%d", &m[i]);
	RMQ_init(M+1);
	for(int i = 0; i < N; i++) {
		int A, B;
		fscanf(fin, "%d%d", &A, &B);
		fprintf(fout, "%d ", RMQ(A-1, B-1));
	}
	return 0;
}
