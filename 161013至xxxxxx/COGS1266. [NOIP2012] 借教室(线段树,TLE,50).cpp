#include <cstdio>
using namespace std;
const int maxn = 1000000+100;
const int INF = 0x7fffffff;
FILE *fin, *fout;
int n, m, A[maxn], ans=-1;
inline int min(int a, int b) { return a<b?a:b; }
int Q_read() {
	int ans = 0;
	char c = 0;
	while(c < '0' || c > '9') c = fgetc(fin);
	while(c >= '0' && c <= '9') {
		ans *= 10;
		ans += c-'0';
		c = fgetc(fin);
	}
	return ans;
}
void Q_write(int a) {
	int tmp = a, now = 5;
	int buf[6];
	while(tmp > 0) {
		buf[now] = tmp%10;
		now--;
		tmp /= 10;
	}
	for(int i = now+1; i <= 5; i++) fputc(buf[i]+'0', fout); 
}
struct SEG {
	int minv[maxn*4];
	int addv[maxn*4];
	SEG(int n) {
		build(1, 1, n);
	}
	void build(int o, int L, int R) {
		addv[o] = 0;
		if(L == R) {
			minv[o] = A[L];
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			minv[o] = min(minv[lc], minv[rc]);
		}
	}
	void maintain(int o, int L, int R) {
		if(L == R) {
			//叶节点特殊处理 
			minv[o] = A[L]+addv[o];
		} else {
			int lc=o*2, rc=o*2+1;
			minv[o] = min(minv[lc], minv[rc])+addv[o];
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
	int qmin(int o, int L, int R, int _add=0) {
		if(L>=oL && R<=oR) {
			return minv[o]+_add;
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			int tans = INF;
			if(M >= oL) tans = min(tans, qmin(lc, L, M, _add+addv[o]));
			if(M < oR) tans = min(tans, qmin(rc, M+1, R, _add+addv[o]));
			return tans;
		}
	}
};
int main() {
	fin = fopen("classrooms.in", "r");
	fout = fopen("classrooms.out", "w");
//	fout = stdout;
//	fscanf(fin, "%d%d", &n, &m);
	n = Q_read(); m = Q_read();
	for(int i = 1; i <= n; i++) {
		//fscanf(fin, "%d", &A[i]);
		A[i] = Q_read();
	}
	SEG *D = new SEG(n);
	for(int i = 1; i <= m; i++) {
		int v, l, r;
		//fscanf(fin, "%d%d%d", &v, &l, &r);
		v = Q_read(); l = Q_read(); r = Q_read();
		D->oL = l; D->oR = r;
		int nowmin = D->qmin(1, 1, n);
		if(nowmin < v) {
			ans = i;
			break;
		} else {
			D->oL = l; D->oR = r; D->av = -v;
			D->add(1, 1, n);
		}
	}
	if(ans == -1) {
		//fprintf(fout, "0\n");
		fputc('0', fout);
		fputc('\n', fout);
	} else {
		//fprintf(fout, "-1\n%d\n", ans);
		fputc('-', fout);
		fputc('1', fout);
		fputc('\n', fout);
		Q_write(ans);
		fputc('\n', fout);
	}
	return 0;
}
