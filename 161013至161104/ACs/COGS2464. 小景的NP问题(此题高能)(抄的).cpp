#include <cstdio>
using namespace std;
typedef unsigned long long ULL;
const ULL MOD = 2147483647;
ULL N, P, ans=0, k=1;
//ULL tmp=0;
FILE *fin, *fout;
int main() {
	fin = fopen("hujingyuan.in", "r");
	fout = fopen("hujingyuan.out", "w");
//	fout = stdout;
	fscanf(fin, "%llu%llu", &N, &P);
//	fscanf(fin, "%I64u%I64u", &N, &P);
	/*
	tmp = P;
	while(tmp*P <= N) {
		ans += (tmp/P-1)*k++;
		ans %= MOD;
		tmp *= P;
	}
	*/
	while(1) {
		if((N/k) < P) break;
        k *= P;
        ans = (ans + N/k) % MOD;
	}
//	ans += (N/P - tmp/P)*k;
	fprintf(fout, "%llu", ans%MOD);
//	fprintf(fout, "%I64u", ans%MOD);
	return 0;
}
