#include <cstdio>
using namespace std;
typedef long long LL;
const LL maxn = 10000+10;
const LL INF = 99999999999;
LL l1, l2, l3, c1, c2, c3, n;
LL A, B, d[maxn], f[maxn];
//LL d2[maxn];
FILE *fin, *fout;
inline LL min(LL a, LL b) { return a<b?a:b; }
inline void swap(LL &a, LL &b) { LL t = a; a = b; b = t; }
LL dis(LL l, LL r) {
	LL dist = d[r] - d[l];
	if(dist <= l1) return c1;
	else if(dist>l1 && dist<=l2) return c2;
	else return c3;
}
int main() {
	fin = fopen("rail.in", "r");
	fout = fopen("rail.out", "w");
//	fout = stdout;
//	fscanf(fin, "%I64d%I64d%I64d%I64d%I64d%I64d", &l1, &l2, &l3, &c1, &c2, &c3);
//	fscanf(fin, "%I64d", &n);
//	fscanf(fin, "%I64d%I64d", &A, &B);
	fscanf(fin, "%lld%lld%lld%lld%lld%lld", &l1, &l2, &l3, &c1, &c2, &c3);
	fscanf(fin, "%lld", &n);
	fscanf(fin, "%lld%lld", &A, &B);
	if(A > B) swap(A, B);//A > BÊ±½»»» 
//	for(LL i = 2; i <= n; i++) fscanf(fin, "%I64d", &d[i]);
	for(LL i = 2; i <= n; i++) fscanf(fin, "%lld", &d[i]);
//	for(LL i = 0, j = A; j <= B; i++, j++) d2[i] = d[j];
	for(LL i = A+1; i <= B; i++) f[i] = INF;
	for(LL i = A+1; i <= B; i++) {
		for(LL j = i; j >= A; j--) {
			if(d[i] - d[j] > l3) break;
//			else if(i == j) f[i] = f[j]; 
			f[i] = min(f[i], f[j] + dis(j, i));
		}
	}
//	fprintf(fout, "%I64d", f[B]);
	fprintf(fout, "%lld", f[B]);
//	fprintf(fout, "%I64d", dis(2,3));
	return 0;
}
