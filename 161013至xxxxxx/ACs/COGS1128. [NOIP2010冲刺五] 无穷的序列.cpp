#include <cstdio>
#include <algorithm>
using namespace std;
FILE *fin, *fout;
int A[50001], n;
int main() {
	fin = fopen("unlessseq.in", "r");
	fout = fopen("unlessseq.out", "w");
//	fout = stdout;
	for(int i = 1; i <= 50000; i++) A[i] = A[i-1]+i;
//	for(int i = 0; i <= 50000; i++) fprintf(fout, "%d\n", A[i]);
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		int p; 
		fscanf(fin, "%d", &p);
		int tmp = lower_bound(A, A+50000, p-1) - A;
//		fprintf(fout, "%d\n", A[tmp]);
		if(A[tmp] == p-1) fprintf(fout, "1\n");
		else fprintf(fout, "0\n");
	}
	return 0;
}
