#include <cstdio>
#include <cstring>

const int maxn = 100000+10;
const int bufsize = 10;

struct SEG {
	int n;
	int maxv[maxn*4], ghmaxv[maxn*4], addv[maxn*4], setv[maxn*4];
	int oL, oR, _addv, _setv;
	SEG(int n) {
		this->n = n;
		memset(setv, -1, sizeof(setv));
		memset(addv, 0, sizeof(addv));
		build(1, 1, n);
	}
	void pushdown(int o) {
		int lc=o*2, rc=o*2+1;
		if(setv[o] != -1) {
			
		}
	}
	void upcurpinfo(int o, int L, int R) {
		pushdown(o); 
	}
	void build(int o, int L, int R) {
		if(L == R) {
			maxv[o] = ghmaxv[o] = A[L];
		} else {
			int M = L+(R-L)/2;
			int lc=o*2, rc=o*2+1;
			build(lc, L, M);
			build(rc, M+1, R);
			upcurpinfo(o, L, R);
		}
	}
};

int T, E, A[maxn], X, Y, Z;
char buf[bufsize];

int main() {
	scanf("%d", &T);
	for(int i = 1; i < T; i++) scanf("%d", &A[i]);
	SEG *d = new SEG(T);
	scanf("%d", &E);
	for(int i = 0; i < E; i++) {
		scanf("%s", buf);
		if(buf[0] == 'Q') {
			scanf("%d%d", &X, &Y);
		} else if(buf[0] == 'A') {
			scanf("%d%d", &X, &Y);
		} else if(buf[0] == 'P') {
			scanf("%d%d%d", &X, &Y, &Z);
		} else if(buf[0] == 'C') {
			scanf("%d%d%d", &X, &Y, &Z);
		}
	}
	return 0;
}
