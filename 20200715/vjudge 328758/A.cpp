#include <cstdio>

const int maxn = 50000+10;
const int INF = 1000000+10;

inline int min(int a, int b) { return a<b?a:b; }
inline int max(int a, int b) { return a>b?a:b; }

struct SEG {
	int n;
	int maxv[maxn*4], minv[maxn*4];
	int oL, oR, _min, _max;
	SEG(int n, int *A) {
		this->n = n;
		this->build(1, 1, n, A);
	}
	void upcurpinfo(int o, int L, int R) {
		int lc=o*2, rc=o*2+1;
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
	}
	void build(int o, int L, int R, int *A) {
		if(L == R) {
			minv[o] = maxv[o] = A[L];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			build(lc, L, M, A);
			build(rc, M+1, R, A);
			upcurpinfo(o, L, R);
		}
	}
	void qmin(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			_min = min(_min, minv[o]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			if(M >= oL) qmin(lc, L, M);
			if(M < oR) qmin(rc, M+1, R);
		}
	}
	int get_min(int L, int R) {
		this->oL = L;
		this->oR = R;
		this->_min = INF;
		this->qmin(1, 1, n);
		return this->_min;
	}
	void qmax(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			_max = max(_max, maxv[o]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			if(M >= oL) qmax(lc, L, M);
			if(M < oR) qmax(rc, M+1, R);
		}
	}
	int get_max(int L, int R) {
		this->oL = L;
		this->oR = R;
		this->_max = -INF;
		this->qmax(1, 1, n);
		return this->_max;
	}
	int get(int L, int R) { return this->get_max(L, R)-this->get_min(L, R); }
};

int N, Q;
int d[maxn];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &d[i]);
	SEG *s = new SEG(N, d);
	for(int i = 0; i < Q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s->get(l, r));
	}
	return 0;
}
