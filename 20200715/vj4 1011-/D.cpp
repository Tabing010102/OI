#include <cstdio>
#include <cstring>

const int maxn = 100000+10;
const int buf_size = 10;

char A[maxn];
int n;

struct Node {
	bool d[26];
	void clear() { memset(d, 0, sizeof(d)); }
};

struct SEG {
	int n;
	Node d[maxn*4];
	int oL, oR; char ov; Node tans;
	void upcurpinfo(int o, int L, int R) {
		int lc=o*2, rc=o*2+1;
		for(int i = 0; i < 26; i++) d[o].d[i] = (d[lc].d[i]||d[rc].d[i]);
	}
	void build(int o, int L, int R) {
		if(L == R) { d[o].d[A[L]-'a'] = true; }
		else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			upcurpinfo(o, L, R);
		}
	}
	void update(int o, int L, int R) {
		if(L == R) {
			d[o].d[A[L]-'a'] = false;
			d[o].d[ov-'a'] = true;
			A[L] = ov;
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			if(M >= oL) update(lc, L, M);
			else update(rc, M+1, R);
			upcurpinfo(o, L, R);
		}
	}
	void query(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			for(int i = 0; i < 26; i++) tans.d[i] = (tans.d[i]||d[o].d[i]);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L+(R-L)/2;
			if(M >= oL) query(lc, L, M);
			if(M < oR) query(rc, M+1, R);
		}
	}
	void execute_update(int pos, char c) {
		oL = pos; ov = c;
		update(1, 1, n);
	}
	int execute_query(int l, int r) {
		tans.clear();
		oL = l, oR = r;
		query(1, 1, n);
		int ans = 0;
		for(int i = 0; i < 26; i++) if(tans.d[i]) ans++;
		return ans;
	}
	SEG(int n) {
		this->n = n;
		build(1, 1, n);
	}
};

int main() {
	scanf("%s", A+1);
	SEG *d = new SEG(strlen(A+1));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int t, l, r; char ts[buf_size];
		scanf("%d", &t);
		if(t == 1) { scanf("%d%s", &l, ts); d->execute_update(l, ts[0]); }
		else { scanf("%d%d", &l, &r); printf("%d\n", d->execute_query(l, r)); }
	}
	return 0;
}
