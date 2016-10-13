#include <cstdio>
using namespace std;
const int maxn = 1e6+100;
const int INF = 10000;
FILE *fin, *fout;
int n, q, H[maxn];
int maxv[2*maxn], qL, qR;
inline int max(int a, int b) { return a<b?b:a; }
/*
void update(int o, int p, int v, int L, int R) {//A[p]=v
	int M = L + (R-L)/2;
	if(L == R) maxv[o] = v;//叶节点，直接更新
	else {
		if(p <= M) update(o*2, p, v, L, M);
		else update(o*2+1, p, v, M+1, R);
		maxv[o] = max(maxv[o*2], maxv[o*2+1]);
	}
}
*/
void build(int o, int L, int R) {
	if(L == R) {
		maxv[o] = H[L];
//		fprintf(fout, "o=%d, L=%d, R=%d, maxv[%d]=%d\n", o, L, R, o, H[L]);
		return;
	} else {
		int M = L + (R-L)/2;
		build(o*2, L, M);
		build(o*2+1, M+1, R);
		maxv[o] = max(maxv[o*2], maxv[o*2+1]);
	}
}
int query(int o, int L, int R) {
//	fprintf(fout, "qL=%d, qR=%d, o=%d, L=%d, R=%d\n", qL, qR, o, L, R);
	if(R < qL || L > qR) return 0;
	int ans = 0, M = L + (R-L)/2;
	if(L >= qL && R <= qR) return maxv[o];
	if(M >= qL) ans = max(ans, query(o*2, L, M));
	if(M < qR) ans = max(ans, query(o*2+1, M+1, R));
	return ans;
}
int main() {
	fin = fopen("climb.in", "r");
	fout = fopen("climb.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n+1; i++) fscanf(fin, "%d", &H[i]);
	build(1, 1, n+1);
	fscanf(fin, "%d", &q);
	for(int i = 1; i <= q; i++) {
		fscanf(fin, "%d%d", &qL, &qR);
		qL++; qR++;
		fprintf(fout, "%d\n", query(1, 1, n+1));
	}
	return 0;
}
