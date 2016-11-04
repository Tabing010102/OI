//这是搞不过去的 
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int maxn = 50000+10;
FILE *fin, *fout;
int n, m, A[maxn];
int gcd(int a, int b) { return b==0?a:gcd(b, a%b); }
LL lcm(LL a, LL b) { return (a/gcd(a, b)*b)%MOD; }
struct SEG {
	int gcdv[maxn*4];
	LL lcmv[maxn*4];
	SEG(int n) {
		this->build(1, 1, n);
	}
	void maintain(int o, int L, int R) {
		if(R > L) {
			int lc=o*2, rc=o*2+1;
			gcdv[o] = gcd(gcdv[lc], gcdv[rc]);
			LL tmp = lcm(lcmv[lc], lcmv[rc]);
//			tmp %= MOD;
			lcmv[o] = tmp;
		}
	}
	void build(int o, int L, int R) {
		if(L == R) {
			lcmv[o] = gcdv[o] = A[L];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
		}
		maintain(o, L, R);
//		printf("build(o=%d, L=%d, R=%d) gcdv=%d, lcmv=%I64d\n", o, L, R, gcdv[o], lcmv[o]);
	}
	int oL, oR;
	int qgcd(int o, int L, int R) {
		if(L == R) {
			return gcdv[o];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			int tans = -1;
			if(M >= oL) tans = qgcd(lc, L, M);
			if(M < oR) {
				int tmp = qgcd(rc, M+1, R);
				if(tans == -1) tans = tmp;
				else tans = gcd(tans, tmp);
			}
			return tans;
		}
	}
	LL qlcm(int o, int L, int R) {
		if(L == R) {
			return lcmv[o];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			LL tans = -1;
			if(M >= oL) tans = qlcm(lc, L, M);
			if(M < oR) {
				LL tmp = qlcm(rc, M+1, R);
				if(tans == -1) tans = tmp;
				else tans = lcm(tans, tmp);
			}
			return tans;
		}
	}
	void execute_command() {
		int l, r;
		fscanf(fin, "%d%d", &l, &r);
		oL = l; oR = r;
		int gv = qgcd(1, 1, n);
		LL lv = qlcm(1, 1, n);
		LL tmp = gv * lv;
//		printf("gv=%d, lv=%I64d, tmp=%I64d, ", gv, lv, tmp);
		tmp %= MOD;
		fprintf(fout, "%d\n", (int)tmp);
//		printf("ans=%d \n", (int)tmp);
	}
};
int main() {
	fin = fopen("Keller_T233.in", "r");
	fout = fopen("Keller_T233.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	if(n <= 0) exit(0);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &A[i]);
	SEG *D = new SEG(n);
	for(int i = 1; i <= m; i++) D->execute_command();
	return 0;
}
