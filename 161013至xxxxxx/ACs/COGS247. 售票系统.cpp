#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 60000+10;
FILE *fin, *fout;
inline int max(int a, int b) { return a<b?b:a; }
struct SEG {
	int maxv[maxn*4];
	int addv[maxn*4];
	SEG(int n) {
		memset(maxv, 0, sizeof(maxv));
		memset(addv, 0, sizeof(addv));
	}
	void maintain(int o, int L, int R) {
		if(L == R) maxv[o] = addv[o];
		else {
			int lc=o*2, rc=o*2+1;
			maxv[o] = max(maxv[lc], maxv[rc])+addv[o];
		}
	}
	int oL, oR, av;
	void add(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			addv[o] += av;
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) add(lc, L, M);
			if(M < oR) add(rc, M+1, R);
		}
		maintain(o, L, R);
	}
	int qmax(int o, int L, int R, int _add=0) {
		if(L>=oL && R<=oR) {
			return maxv[o]+_add;
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans = max(ans, qmax(lc, L, M, _add+addv[o]));
			if(M < oR) ans = max(ans, qmax(rc, M+1, R, _add+addv[o]));
			return ans;
		}
	}
};
int n, max_seats, t;
int main() {
	fin = fopen("railway.in", "r");
	fout = fopen("railway.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d%d", &n, &max_seats, &t);
	SEG *D = new SEG(n);
	while(t--) {
		int l, r, v;
		fscanf(fin, "%d%d%d", &l ,&r, &v);
		r--;
		if(l > r) { fprintf(fout, "YES\n"); continue; }
		D->oL = l; D->oR = r;
		int nm = D->qmax(1, 1, n);
		if(max_seats-nm >= v) {
			fprintf(fout, "YES\n");
			D->oL = l; D->oR = r; D->av = v;
			D->add(1, 1, n);
		} else {
			fprintf(fout, "NO\n");
		}
	}
	return 0;
}
