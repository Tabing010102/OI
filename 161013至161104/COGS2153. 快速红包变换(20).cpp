#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000+100;
const int INF = 100000+100;
const char cmds[9][20] = {"Cadd", "Cchange", "Cbmax", "Cbmin", "Qsum", "Qwmax", "Qwmin", "Qnmax", "Qnmin"};
FILE *fin, *fout;
int n, m, A[maxn];
int max(int a, int b) { return a<b?b:a; }
int min(int a, int b) { return a<b?a:b; }
struct SEG {
	int n;
	int maxv[4*maxn], minv[4*maxn], sumv[4*maxn];
	int nmax[4*maxn], nmin[4*maxn];
	int addv[4*maxn], setv[4*maxn];
	SEG(int a) {
		this->n = a;
		this->build(1, 1, a);
	} 
	int oL, oR;
	/*
	void maintain(int o, int L, int R) {
		if(setv[o] >= 0) {
			maxv[o] = minv[o] = setv[o];
			sumv[o] = setv[o] * (R-L+1);
			nmax[o] = nmin[o] = R-L+1;
		} else {
			int lc = o*2, rc = o*2+1;
			sumv[o] = sumv[lc] + sumv[rc];
			//处理maxv & nmax 
			if(maxv[lc] == maxv[rc]) {
				maxv[o] = maxv[lc];
				nmax[o] = nmax[lc] + nmax[rc];
			} else if(maxv[lc] > maxv[rc]) {
				maxv[o] = maxv[lc];
				nmax[o] = nmax[lc];
			} else {
				maxv[o] = maxv[rc];
				nmax[o] = nmax[rc];
			}
			//处理minv & nmin
			if(minv[lc] == minv[rc]) {
				minv[o] = minv[lc];
				nmin[o] = nmin[lc] + nmin[rc];
			} else if(minv[lc] > minv[rc]) {
				minv[o] = minv[rc];
				nmin[o] = nmin[rc];
			} else {
				minv[o] = minv[lc];
				nmin[o] = nmin[lc];
			}
		}
		maxv[o] += addv[o];
		minv[o] += addv[o];
		sumv[o] += addv[o] * (R-L+1);
	}
	*/
	void maintain(int o, int L, int R) {
		int lc = o*2, rc = o*2+1;
		if(R > L) {
			sumv[o] = sumv[lc] + sumv[rc];
			//处理maxv&nmax 
			if(maxv[lc] == maxv[rc]) { maxv[o] = maxv[lc]; nmax[o] = nmax[lc] + nmax[rc]; }
			else if(maxv[lc] > maxv[rc]) { maxv[o] = maxv[lc]; nmax[o] = nmax[lc]; }
			else { maxv[o] = maxv[rc]; nmax[o] = nmax[rc]; }
			//处理minv&nmin
			if(minv[lc] == minv[rc]) { minv[o] = minv[lc]; nmin[o] = nmin[lc] + nmin[rc]; }
			else if(minv[lc] > minv[rc]) { minv[o] = minv[rc]; nmin[o] = nmin[rc]; }
			else { minv[o] = minv[lc]; nmin[o] = nmin[lc]; }
		}
		if(setv[o] >= 0) { minv[o] = maxv[o] = setv[o]; sumv[o] = setv[o]*(R-L+1); nmax[o] = nmin[o] = R-L+1; }
		if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o]*(R-L+1); }	
	}
	void build(int o, int L, int R) {
		setv[o] = -1;
		if(L == R) {
			maxv[o] = minv[o] = sumv[o] = A[L];
			nmax[o] = nmin[o] = 1;
			addv[o] = 0;
		} else {
			int lc = o*2, rc =o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			maintain(o, L, R);
		} 
//		printf("build(o=%d, L=%d, R=%d) maxv=%d, minv=%d, sumv=%d, nmax=%d, nmin=%d, setv=%d, addv=%d\n", o, L, R, maxv[o], minv[o], sumv[o], nmax[o], nmin[o], setv[o], addv[o]);
	}
	void pushdown(int o) {
		int lc = o*2, rc = o*2+1;
		if(setv[o] >= 0) {
			setv[lc] = setv[rc] = setv[o];
			addv[lc] = addv[rc] = 0;
			setv[o] = -1;
		}
		if(addv[o]) {
			addv[lc] += addv[o];
			addv[rc] += addv[o];
			addv[o] = 0;
		}
	}
	int av;
	void add(int o, int L, int R) {
		if(L >= oL && R <= oR) {
			addv[o] += av;
//			fprintf(fout, "addv[o=%d] = av=%d, L=%d, R=%d\n", o, av, L, R);
		} else {
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) add(lc, L, M); else maintain(lc, L, M);
			if(M < oR) add(rc, M+1, R); else maintain(rc, M+1, R);
		}
		maintain(o, L, R);
	}
	/*
	void pushdown(int o) { 
		if(setv[o] >= 0) {
			int lc = o*2, rc = o*2+1;
			setv[lc] = setv[rc] = setv[o]; 
			setv[o] = -1;
			if(addv[o] > 0) {
				addv[lc] = addv[rc] = addv[o];
				addv[o] = 0;
			}
		}
	}
	*/
	int sv;
	void set(int o, int L, int R) {
		if(L >= oL && R <= oR) {
			setv[o] = sv; addv[o] = 0;
		} else {
//			fprintf(fout, "set(o=%d, L=%d, R=%d),oL=%d, oR=%d, sv=%d, pushdown(o=%d)\n", o, L, R, oL, oR, sv, o);
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) set(lc, L, M); else maintain(lc, L, M);
			if(M < oR) set(rc, M+1, R); else maintain(rc, M+1, R);
		}
		maintain(o, L, R);
	}
	/*
	int soL, soR, smaxv;
	void setmax(int o, int L, int R, int _add=0) {
		if(L == R) {
			if(smaxv > maxv[o]+_add) {
				oL = L; oR = R; sv = smaxv;
//				fprintf(fout, "setmax(o=%d, L=%d, R=%d, _add=%d), L==R, oL=L=%d, oR=R=%d, sv=smaxv=%d\n", o, L, R, _add, oL, oR, sv);
				set(1, 1, n);
			} else return;
		} else {
			if(smaxv > maxv[o]+_add) {
				oL = L; oR = R; sv=smaxv;
				set(1, 1, n);
			} else {
				int lc = o*2, rc = o*2+1;
				int M = L + (R-L)/2;
				if(M >= soL) setmax(lc, L, M, _add+addv[o]);
				if(M < soR) setmax(rc, M+1, R, _add+addv[o]);
			}
		}
	}
	int sminv;
	void setmin(int o, int L, int R, int _add=0) {
		if(L == R) {
			if(sminv < minv[o]+_add) {
				oL = L; oR = R; sv = sminv;
//				fprintf(fout, "setmin(o=%d, L=%d, R=%d, _add=%d), L==R, oL=L=%d, oR=R=%d, sv=sminv=%d\n", o, L, R, _add, oL, oR, sv);
				set(1, 1, n);
			} else return;
		} else {
			if(sminv > minv[o]+_add) {
				oL = L; oR = R; sv=sminv;
				set(1, 1, n);
			} else {
				int lc = o*2, rc = o*2+1;
				int M = L + (R-L)/2;
				if(M >= soL) setmin(lc, L, M, _add+addv[o]);
				if(M < soR) setmin(rc, M+1, R, _add+addv[o]);
			}
		}
	}
	*/
	int uv, p;
	void update(int o, int L, int R) {
		int lc = o*2, rc = o*2+1;
		if(L == R) {
			setv[o] = -1; addv[o] = 0;
			maxv[o] = minv[o] = sumv[o] = uv;
			return;
		} else {
			int M = L + (R-L)/2;
			if(M >= p) update(lc, L, M);
			else update(rc, M+1, R);
		}
		maintain(o, L ,R);
	}
	int soL, soR;
	int smaxv;
	void setmax(int o, int L, int R, int _add=0) {
		if(L>=soL && R<=soR) {
			if(setv[o] >= 0) {
				if(smaxv > maxv[o]+_add) { oL = L; oR = R; sv = smaxv; set(1, 1, n); }
			} else if(L == R) {
				if(smaxv > maxv[o]+_add) { p = L; uv = smaxv; update(1, 1, n); }
//				if(smaxv > maxv[o]+_add) { oL = L; oR = R; sv = smaxv; set(1, 1, n); }
			}
		} else {
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= soL) setmax(lc, L, M, _add+addv[o]);
			if(M < soR) setmax(rc, M+1, R, _add+addv[o]);
		}
	}
	int sminv;
	void setmin(int o, int L, int R, int _add=0) {
		if(L>=soL && R<=soR) {
			if(setv[o] >= 0) {
				if(sminv < minv[o]+_add) { oL = L; oR = R; sv = sminv; set(1, 1, n); }
			} else if(L == R) {
				if(sminv < minv[o]+_add) { p = L; uv = sminv; update(1, 1, n); }
//				if(sminv < minv[o]+_add) { oL = L; oR = R; sv = sminv; set(1, 1, n); }
			}
		} else {
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= soL) setmin(lc, L, M, _add+addv[o]);
			if(M < soR) setmin(rc, M+1, R, _add+addv[o]);
		}
	}
	/*
	int qsum(int o, int L, int R, int _add=0) {
//		fprintf(fout, "qsum(o=%d, L=%d, R=%d, _add=%d)\n", o, L, R, _add);
		if(setv[o] >= 0) {
			return (setv[o] + addv[o] + _add) * (min(R, oR) - max(L, oL) +1);
		} else if(L>=oL && R<=oR) {
//			fprintf(fout, "retrun sumv[o=%d]+_add=%d = %d\n", o, _add, sumv[o]+_add);
			return sumv[o] + _add*(R-L+1);
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans += qsum(lc, L, M, _add+addv[o]);
			if(M < oR) ans += qsum(rc, M+1, R, _add+addv[o]);
			return ans;
		}
	}
	int qmax(int o, int L, int R, int _add=0) {
		if(setv[o] >= 0) {
			return setv[o] + _add + addv[o];
		} else if(L>=oL && R<=oR) {
			return maxv[o] + _add;
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans = max(ans, qmax(lc, L, M, _add+addv[o]));
			if(M < oR) ans = max(ans, qmax(rc, M+1, R, _add+addv[o]));
			return ans;
		}
	}
	int qmin(int o, int L, int R, int _add=0) {
		if(setv[o] >= 0) {
			return setv[o] + _add + addv[o];
		} else if(L>=oL && R<=oR) {
			return minv[o] + _add;
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			int ans = INF;
			if(M >= oL) ans = min(ans, qmin(lc, L, M, _add+addv[o]));
			if(M < oR) ans = min(ans, qmin(rc, M+1, R, _add+addv[o]));
			return ans;
		}
	}
	int qnmax(int o, int L, int R) {
		if(setv[o] >= 0) {
			return nmax[o];
		} else if(L>=oL && R<=oR) {
			return nmax[o];
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans += qnmax(lc, L, M);
			if(M < oR) ans += qnmax(rc, M+1, R);
			return ans;
		}
	}
	int qnmin(int o, int L, int R) {
		if(setv[o] >= 0) {
			return nmin[o];
		} else if(L>=oL && R<=oR){
			return nmin[o];
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans += qnmin(lc, L, M);
			if(M < oR) ans += qnmin(rc, M+1, R);
			return ans;
		}
	}
	*/
	int _sum;
	void qsum(int o, int L, int R, int _add=0) {
		if(setv[o] >= 0) {
			int v = setv[o] + _add + addv[o];
			_sum += v * (min(R, oR) - max(L, oL) + 1);
		} else if(L>=oL && R<=oR) {
			_sum += sumv[o] + _add * (R-L+1);
		} else {
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qsum(lc, L, M, _add+addv[o]);
			if(M < oR) qsum(rc, M+1, R, _add+addv[o]);
		}
	}
	void execute_commands() {
		char buf[20];
		fscanf(fin, "%s", buf);
		int op = 0;
		for(int i = 0; i < 9; i++) if(strcmp(cmds[i], buf) == 0) { op = i; break;}
		int l, r, a, ans;
		switch(op) {
			case 0:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r; av = a;
//				fprintf(fout, "add(), oL=%d, oR=%d, av=%d\n", oL, oR, av);
				add(1, 1, n);//从A[oL]到A[oR]每个红包钱数加a
				break;
			case 1:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r; sv = a;
//				fprintf(fout, "set, oL=%d, oR=%d\n", oL, oR);
				set(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为a
				break;
			case 2:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				soL = l; soR = r; smaxv = a;
				setmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为max(A[i],a)
				break;
			case 3:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				soL = l; soR = r; sminv = a;
				setmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为min(A[i],a)
				break;
			case 4:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
//				fprintf(fout, "qsum(), oL=%d, oR=%d\n", oL, oR);
				_sum = 0;
				qsum(1, 1, n);//求从A[oL]到A[oR]每个红包钱数和
				fprintf(fout, "%d\n", _sum);
				break;
				/*
			case 5:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				_max = -INF;
				qmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最大值
				fprintf(fout, "%d\n", _max);
				break;
			case 6:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				_min = INF;
				qmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最小值
				fprintf(fout, "%d\n", _min);
				break;
			case 7:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qnmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最大值的个数
				fprintf(fout, "%d\n", ans);
				break;
			case 8:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qnmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最小值的个数
				fprintf(fout, "%d\n", ans);
				break;
				*/
		}
	}
};
int main() {
	fin = fopen("redbag.in", "r");
	fout = fopen("redbag.out", "w");
	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &A[i]);
	SEG *D = new SEG(n);
	fscanf(fin, "%d", &m);
	for(int i = 1; i <= m; i++) D->execute_commands();
	return 0;
}
