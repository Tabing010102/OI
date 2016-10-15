#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 800000+100;
FILE *fin, *fout;
int A[maxn], len[maxn];
int id, n, q;
inline int max(int a, int b) { return a<b?b:a; }
inline int min(int a, int b) { return a<b?a:b; }

struct SEG {
	int maxv[4*maxn];
	int n;
	SEG(int n) {
		this->n = n;
		this->build(1, 1, n);
	}
	void build(int o, int L, int R) {
		if(L == R) {
			maxv[o] = A[L];
//			len[L] = dlen(A[L]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			maxv[o] = max(maxv[lc], maxv[rc]);
		}
	}
	int oL, oR;
	void qmax(int o, int L, int R, int &ans) {
		if(L>=oL && R<=oR) {
			ans = max(ans, maxv[o]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qmax(lc, L, M, ans);
			if(M < oR) qmax(rc, M+1, R, ans);
		}
	}
	int qopv;
	void update(int o, int L, int R) {
		if(L == R) {
			if(maxv[o] == 0) return;
			int opv = qopv;
//			fprintf(fout, "len[L=%d]=%d\n", L, len[L]);
			opv %= len[L];
			int tmp = maxv[o], xi=1;
			for(int i = 1; i <= opv; i++) xi *= 10;
			int tans = 0;
			for(int i = 1; i <= len[L]-opv; i++) {
				if(tmp == 0) tmp = 1;
				tans += (tmp%10)*xi;
				xi *= 10; tmp /= 10;
			}
			xi = 1;
			for(int i = len[L]-opv+1; i <= len[L]; i++) {
				tans += (tmp%10)*xi;
				xi *= 10; tmp /= 10;
			}
			maxv[o] = tans;
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) update(lc, L, M);
			if(M < oR) update(rc, M+1, R);
			maxv[o] = max(maxv[lc], maxv[rc]);
		}
	}
	void execute_command() {
		char buf[20];
		fscanf(fin, "%s", buf);
		if(buf[0] == 'Q') {
			fscanf(fin ,"%d%d", &oL, &oR);
			int ans = 0;
			qmax(1, 1, n, ans);
			fprintf(fout, "%d\n", ans);
		} else {
			fscanf(fin, "%d%d%d", &oL, &oR, &qopv);
			update(1, 1, n);
		}
	}
};
int dlen(int A) {
	if(A == 0) return 1;
	int l = 0;
	while(A) {
		l++;
		A /= 10;
	}
	return l;
}
int main() {
	fin = fopen("crixalis.in", "r");
	fout = fopen("crixalis.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &id);
	fscanf(fin, "%d%d", &n, &q);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &A[i]);
	for(int i = 1; i <= n; i++) len[i] = dlen(A[i]);
	SEG *D = new SEG(n);
	for(int i = 1; i <= q; i++) D->execute_command();
	return 0;
}
