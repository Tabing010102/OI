#include <cstdio>

const int maxn = 1000+10;
const int INF = 0x7fffffff;

int d[maxn], n, ans=0;

inline int min(int a, int b) { return a<b?a:b; }
inline int max(int a, int b) { return a>b?a:b; }

struct SEG {
	int n;
	int minv[maxn*4];
	void build(int o, int L, int R) {
		if(L == R) {
			minv[o] = d[L];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			minv[o] = min(minv[lc], minv[rc]);
		}
	}
	int oL, oR, _minv;
	void qmin(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			_minv = min(_minv, minv[o]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			if(M >= oL) qmin(lc, L, M);
			if(M < oR) qmin(rc, M+1, R);
		}
	}
	SEG(int n) { this->n = n; build(1, 1, n); }
	int getmin(int L, int R) {
		oL = L; oR = R;
		_minv = INF;
		qmin(1, 1, n);
		return _minv;
	}
};

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	SEG *s = new SEG(n);
	for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) ans = max(ans, s->getmin(i, j)*(j-i+1));
	printf("%d", ans);
	return 0;
}
