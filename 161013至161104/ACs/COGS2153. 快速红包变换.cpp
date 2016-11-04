#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100000+100;
const int INF = 0x3f3f3f3f;
const char cmds[9][20] = {"Cadd", "Cchange", "Cbmax", "Cbmin", "Qsum", "Qwmax", "Qwmin", "Qnmax", "Qnmin"};
FILE *fin, *fout;
int n, m, A[maxn];
int max(int a, int b) { return a<b?b:a; }
int min(int a, int b) { return a<b?a:b; }
inline int Q_read() {
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
inline void Q_write(int a) {
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
	int n;
	int maxv[4*maxn], minv[4*maxn], sumv[4*maxn];
	int nmax[4*maxn], nmin[4*maxn];
	int addv[4*maxn], setv[4*maxn];
	SEG(int n) {
		this->n = n;
		this->build(1, 1, n);
	} 
	int oL, oR;
	void upcurpinfo(int o, int L, int R) {
		int lc = o*2, rc = o*2+1;
		if(setv[o] != INF) {
			minv[o] = maxv[o] = setv[o];
			sumv[o] = setv[o]*(R-L+1);
			nmax[o] = nmin[o] = R-L+1;
		} else {
			if(L == R) {
				sumv[o] = minv[o] = maxv[o] = A[L];
				nmax[o] = nmin[o] = 1;
			} else {
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
		}
		if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o]*(R-L+1); }	
	}
	void build(int o, int L, int R) {
//		printf("build(o=%d, L=%d, R=%d) maxv=%d, minv=%d, sumv=%d, nmax=%d, nmin=%d, setv=%d, addv=%d\n", o, L, R, maxv[o], minv[o], sumv[o], nmax[o], nmin[o], setv[o], addv[o]);
		setv[o] = INF; addv[o] = 0;
		if(L == R) {
			maxv[o] = minv[o] = sumv[o] = A[L];
			nmax[o] = nmin[o] = 1;
		} else {
			int lc = o*2, rc =o*2+1;
			int M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			upcurpinfo(o, L, R);
		} 
//		printf("build(o=%d, L=%d, R=%d) maxv=%d, minv=%d, sumv=%d, nmax=%d, nmin=%d, setv=%d, addv=%d\n", o, L, R, maxv[o], minv[o], sumv[o], nmax[o], nmin[o], setv[o], addv[o]);
	}
	void pushdown(int o) {//pushdown之后需更新左右子节点 
		int lc = o*2, rc = o*2+1;
		if(setv[o] != INF) {
			setv[lc] = setv[rc] = setv[o];
			addv[lc] = addv[rc] = 0;
			setv[o] = INF;
		}
		if(addv[o]) {
			addv[lc] += addv[o];
			addv[rc] += addv[o];
			addv[o] = 0;
		}
	}
	int av;
	void add(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			addv[o] += av;
//			printf("addv[o=%d] = av=%d, L=%d, R=%d, oL=%d, oR=%d\n", o, av, L, R, oL, oR);
		} else {
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) add(lc, L, M); else upcurpinfo(lc, L, M);
			if(M < oR) add(rc, M+1, R); else upcurpinfo(rc, M+1, R);
		}
		upcurpinfo(o, L, R);
	}
	int sv;
	void set(int o, int L, int R) {
		if(L>=oL && R<=oR) {
			setv[o] = sv; addv[o] = 0;
		} else {
//			fprintf(fout, "set(o=%d, L=%d, R=%d),oL=%d, oR=%d, sv=%d, pushdown(o=%d)\n", o, L, R, oL, oR, sv, o);
			pushdown(o);
			int lc = o*2, rc = o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) set(lc, L, M); else upcurpinfo(lc, L, M);
			if(M < oR) set(rc, M+1, R); else upcurpinfo(rc, M+1, R);
		}
		upcurpinfo(o, L, R);
	}
	/*
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
		upcurpinfo(o, L ,R);
	}
	*/
	int soL, soR, smaxv;
	//setmax/min操作需全部统计再修改 
	struct sd {
		int L, R, sv;
	};
	vector<sd> svinfo;
	void setmax(int o, int L, int R, int _add=0) {
		int lc=o*2, rc=o*2+1;
		int M = L + (R-L)/2;
		if(setv[o] != INF) {
			if(L>=soL && R<=soR) {
				int tmp = setv[o]+_add+addv[o];
				if(tmp < smaxv) {
					/*oL = L; oR = R; sv = smaxv;//-_add;//set操作已把所有add值pushdown
					set(1, 1, n);*/
					svinfo.push_back((sd){L, R, smaxv});
				}
			} else {
				pushdown(o);
				if(M >= soL) setmax(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
				if(M < soR) setmax(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
			}
			upcurpinfo(o, L, R);
			return;
		}
		/*if(L == R) {//边界一:已经到达叶节点 
			if(smaxv > maxv[o]) {
				p = L;
				uv = smaxv;
				update(1, 1, n);
			}	
		} else 
		*/
		if(L>=soL && R<=soR) {//边界二三需满足:操作区间完全包含当前区间 
			if(smaxv >= maxv[o]+_add) {//边界二:当前区间的最大值小于等于smaxv,可直接把当前整个区间设置为smaxv 
				/*oL = L; oR = R; sv = smaxv;
				set(1, 1, n);*/
				svinfo.push_back((sd){L, R, smaxv});
			} else if(smaxv <= minv[o]+_add) {//边界三:当前区间最小值大于等于smaxv,无需处理 
				return;
			} else {
				if(M >= soL) setmax(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
				if(M < soR) setmax(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
			}
		} else {
			if(M >= soL) setmax(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
			if(M < soR) setmax(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
		}
		upcurpinfo(o, L, R);
	}
	int sminv;
	void setmin(int o, int L, int R, int _add=0) {
		int lc=o*2, rc=o*2+1;
		int M = L + (R-L)/2;
		if(setv[o] != INF) {
			if(L>=soL && R<=soR) {
				int tmp = setv[o]+_add+addv[o];
				if(tmp > sminv) {
					/*oL = L; oR = R; sv = sminv;//-_add;//set操作已把所有add值pushdown
					set(1, 1, n);*/
					svinfo.push_back((sd){L, R, sminv});
				}
			} else {
//				printf("setmin(o=%d, L=%d, R=%d, _add=%d)->pushdown(o=%d, [L=%d, R=%d]), soL=%d, soR=%d\n", o, L, R, _add, o, L, R, soL, soR);
				pushdown(o);
				if(M >= soL) setmin(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
				if(M < soR) setmin(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
			}
			upcurpinfo(o, L, R);
			return;
		}
		/*if(L == R) {
			if(sminv < minv[o]) {
				p = L;
				uv = sminv;
				update(1, 1, n);
			}
		} else*/
		if(L>=soL && R<=soR) {
			if(sminv <= minv[o]+_add) {
				/*oL = L; oR = R; sv = sminv;
				set(1, 1, n);*/
				svinfo.push_back((sd){L, R, sminv});
			} else if(sminv >= maxv[o]+_add) {
				return;
			} else {
				if(M >= soL) setmin(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
				if(M < soR) setmin(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
			}
		} else {
			if(M >= soL) setmin(lc, L, M, _add+addv[o]); else upcurpinfo(lc, L, M);
			if(M < soR) setmin(rc, M+1, R, _add+addv[o]); else upcurpinfo(rc, M+1, R);
		}
		upcurpinfo(o, L, R);
	}
	int _sum;
	void qsum(int o, int L, int R, int _add=0) {
		if(setv[o] != INF) {
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
	int _max;
	void qmax(int o, int L, int R, int _add=0) {
		if(setv[o] != INF) {
			int v = setv[o] + _add + addv[o];
			_max = max(_max, v);
		} else if(L>=oL && R<=oR) {
			_max = max(_max, maxv[o]+_add);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qmax(lc, L, M, _add+addv[o]);
			if(M < oR) qmax(rc, M+1, R, _add+addv[o]);
		}
	}
	int _min;
	void qmin(int o, int L, int R, int _add=0) {
		if(setv[o] != INF) {
			int v = setv[o] + _add + addv[o];
			_min = min(_min, v);
		} else if(L>=oL && R<=oR) {
			_min = min(_min, minv[o]+_add);
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qmin(lc, L, M, _add+addv[o]);
			if(M < oR) qmin(rc, M+1, R, _add+addv[o]);
		}
	}
	int _nmax, _nowmax;
	void qnmax(int o, int L, int R, int _add=0) {
		if(setv[o] != INF) {
			int tmp = min(R, oR) - max(L, oL) + 1;
			if(_nowmax == setv[o]+_add+addv[o]) _nmax += tmp;
			else if(_nowmax < setv[o]+_add+addv[o]) { _nowmax = setv[o]+_add+addv[o]; _nmax = tmp; }
		} else if(L>=oL && R<=oR) {
			if(_nowmax == maxv[o]+_add) _nmax += nmax[o];
			else if(_nowmax < maxv[o]+_add) { _nowmax = maxv[o]+_add; _nmax = nmax[o]; }
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qnmax(lc, L, M, _add+addv[o]);
			if(M < oR) qnmax(rc, M+1, R, _add+addv[o]);
		}
	}
	int _nmin, _nowmin;
	void qnmin(int o, int L, int R, int _add=0) {
		if(setv[o] != INF) {
			int tmp = min(R, oR) - max(L, oL) + 1;
			if(_nowmin == setv[o]+_add+addv[o]) _nmin += tmp;
			else if(_nowmin > setv[o]+_add+addv[o]) { _nowmin = setv[o]+_add+addv[o]; _nmin = tmp; }
		} else if(L>=oL && R<=oR) {
			if(_nowmin == minv[o]+_add) _nmin += nmin[o];
			else if(_nowmin > minv[o]+_add) { _nowmin = minv[o]+_add; _nmin = nmin[o]; }
		} else {
			int lc=o*2, rc=o*2+1;
			int M = L + (R-L)/2;
			if(M >= oL) qnmin(lc, L, M, _add+addv[o]);
			if(M < oR) qnmin(rc, M+1, R, _add+addv[o]);
		}
	}
	void execute_command() {
		char buf[20];
//		printf("Reading(buf)...");
		fscanf(fin, "%s", buf);
//		printf(" buf=%s\n", buf);
		int op = 0;
		for(int i = 0; i < 9; i++) if(strcmp(cmds[i], buf) == 0) { op = i; break;}
		int l, r, a;
		switch(op) {
			case 0:
//				fscanf(fin, "%d%d%d", &l, &r, &a);
				l = Q_read(); r = Q_read(); a = Q_read();
				
				oL = l; oR = r; av = a;
//				fprintf(fout, "add(), oL=%d, oR=%d, av=%d\n", oL, oR, av);
				add(1, 1, n);//从A[oL]到A[oR]每个红包钱数加a
				break;
			case 1:
//				fscanf(fin, "%d%d%d", &l, &r, &a);
				l = Q_read(); r = Q_read(); a = Q_read();
				
				oL = l; oR = r; sv = a;
//				fprintf(fout, "set, oL=%d, oR=%d\n", oL, oR);
				set(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为a
				break;
			case 2:
//				fscanf(fin, "%d%d%d", &l, &r, &a);
				l = Q_read(); r = Q_read(); a = Q_read();
				
				soL = l; soR = r; smaxv = a;
				svinfo.clear();
				setmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为max(A[i],a)
				for(int i = 0; i < svinfo.size(); i++) {
					sd &x = svinfo[i];
					oL = x.L; oR = x.R; sv = x.sv;
					set(1, 1, n);
				}
				break;
			case 3:
//				fscanf(fin, "%d%d%d", &l, &r, &a);
				l = Q_read(); r = Q_read(); a = Q_read();
				
				soL = l; soR = r; sminv = a;
				svinfo.clear();
				setmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数变为min(A[i],a)
				for(int i = 0; i < svinfo.size(); i++) {
					sd &x = svinfo[i];
					oL = x.L; oR = x.R; sv = x.sv;
					set(1, 1, n);
				}
				break;
			case 4:
//				fscanf(fin, "%d%d", &l, &r);
				l = Q_read(); r = Q_read();
				
				oL = l; oR = r;
//				fprintf(fout, "qsum(), oL=%d, oR=%d\n", oL, oR);
				_sum = 0;
				qsum(1, 1, n);//求从A[oL]到A[oR]每个红包钱数和
				fprintf(fout, "%d\n", _sum);
				break;
			case 5:
//				fscanf(fin, "%d%d", &l, &r);
				l = Q_read(); r = Q_read();
				
				oL = l; oR = r;
				_max = -INF;
				qmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最大值
				fprintf(fout, "%d\n", _max);
				break;
			case 6:
//				fscanf(fin, "%d%d", &l, &r);
				l = Q_read(); r = Q_read();
				
				oL = l; oR = r;
				_min = INF;
				qmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最小值
				fprintf(fout, "%d\n", _min);
				break;
			case 7:
//				fscanf(fin, "%d%d", &l, &r);
				l = Q_read(); r = Q_read();
				
				oL = l; oR = r;
				_nowmax = -INF; _nmax = 0;
				qnmax(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最大值的个数
				fprintf(fout, "%d\n", _nmax);
				break;
			case 8:
//				fscanf(fin, "%d%d", &l, &r);
				l = Q_read(); r = Q_read();
				
				oL = l; oR = r;
				_nowmin = INF; _nmin = 0;
				qnmin(1, 1, n);//从A[oL]到A[oR]每个红包钱数的最小值的个数
				fprintf(fout, "%d\n", _nmin);
				break;
		}
		/*
		printf("op=%s, l=%d, r=%d, a=%d\n", buf, l, r, a);
		for(int i = 1; i <= n; i++) {
			_sum = 0;
			oL = oR = i;
			qsum(1, 1, n);
			printf("%d ", _sum);
		}
		printf("\n");
		*/
	}
};
int main() {
	fin = fopen("redbag.in", "r");
	fout = fopen("redbag.out", "w");
//	fout = stdout;
//	printf("Reading(n)..."); 

//	fscanf(fin, "%d", &n);
	n = Q_read();
	
//	printf(" n=%d\n", n); 
//	printf("Reading(A[])..."); 

//	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &A[i]);
	for(int i = 1; i <= n; i++) A[i] = Q_read();
	
//	printf("A: ");
//	for(int i = 1; i <= n; i++) printf("%d ", A[i]);
//	printf("\n");
	SEG *D = new SEG(n);
	
//	fscanf(fin, "%d", &m);
	m = Q_read();
	
	for(int i = 1; i <= m; i++) D->execute_command();
	return 0;
}
