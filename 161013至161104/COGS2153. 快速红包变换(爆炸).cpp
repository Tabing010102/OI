#include <cstdio>//boom
#include <cstring>
using namespace std;
const int maxn = 100000+100;
const int INF = 1000000;
int A[maxn], n, m;//��� 
FILE *fin, *fout;
const char cmds[9][20] = {"Cadd", "Cchange", "Cbmax", "Cbmin", "Qsum", "Qwmax", "Qwmin", "Qnmax", "Qnmin"};
inline int max(int a, int b) { return a<b?b:a; }
inline int min(int a, int b) { return a<b?a:b; }
struct SEG {
	int n;//�������
	int addv[2*maxn], setv[2*maxn];
	int sumv[2*maxn], maxv[2*maxn], minv[2*maxn];
	int nmax[2*maxn], nmin[2*maxn];
	int oL, oR;//����������
	SEG(int a) {
		this->n = a;
		this->build(1, 1, a);
	}
	void build(int o, int L, int R) {//o��ǰ�ڵ�,[L,R]��ǰ����
		if(L == R) {
			sumv[o] = maxv[o] = minv[o] = A[L];
			nmax[o] = nmin[o] = 1;
			setv[o] = -1; addv[o] = 0;
		} else {
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			build(lc, L, M);
			build(rc, M+1, R);
			//�������� 
			sumv[o] = sumv[lc] + sumv[rc];
			addv[o] = 0; setv[o] = -1;
			//����maxv
			if(maxv[lc] == maxv[rc]) {//��==��
				maxv[o] = maxv[lc];
				nmax[lc] = nmax[lc] + nmax[rc];
//				fprintf(fout, "nmax[o=%d] = nmax[lc=%d] + nmax[rc=%d] = %d\n", o, lc, rc, nmax[o]);
			} else if(maxv[lc] > maxv[rc]) {//��>��
				maxv[o] = maxv[lc];
				nmax[o] = nmax[lc];
//				fprintf(fout, "nmax[o=%d] = nmax[lc=%d] = %d\n", o, lc, nmax[o]);
			} else {//��>��
				maxv[o] = maxv[rc];
				nmax[o] = nmax[rc];
//				fprintf(fout, "nmax[o=%d] = nmax[rc=%d] = %d\n", o, rc, nmax[o]);
			}
			//����minv
			if(minv[lc] == minv[rc]) {//��==��
				minv[o] = minv[lc];
				nmin[o] = nmin[lc] + nmin[rc];
//				fprintf(fout, "nmin[o=%d] = nmin[lc=%d] + nmin[rc=%d] = %d\n", o, lc, rc, nmin[o]);
			} else if(minv[lc] > minv[rc]) {//��>��
				minv[o] = minv[rc];
				nmin[o] = nmin[rc];
//				fprintf(fout, "nmin[o=%d] = nmin[rc=%d] = %d\n", o, rc, nmin[o]);
			} else {//��>��
				minv[o] = minv[lc];
				nmin[o] = nmin[lc];
//				fprintf(fout, "nmin[o=%d] = nmin[lc=%d] = %d\n", o, lc, nmin[o]);
			}
		}
//		fprintf(fout, "build(o=%d, L=%d, R=%d) addv[%d]=%d, setv[%d]=%d, sumv[%d]=%d, maxv[%d]=%d, minv[%d]=%d, nmax[%d]=%d, nmin[%d]=%d\n", o, L, R, o, addv[o], o, setv[o], o, sumv[o], o, maxv[o], o, minv[o], o, nmax[o], o, nmin[o]);
	}
	void maintain(int o, int L, int R) { //ά���ڵ�o,����Ӧ����[L,R]
		int lc = o*2, rc = o*2+1;
		if(setv[o] >= 0) {
			maxv[o] = minv[o] = setv[o];
			sumv[o] = setv[o] * (R-L+1);
			nmax[o] = nmin[o] = R-L+1;
		} else {//����setvӰ��
			sumv[o] = sumv[lc] + sumv[rc];
			//����maxv
//			if(maxv[o]<=maxv[lc] && maxv[o]<=maxv[rc])
			if(maxv[lc] == maxv[rc]) {//��==��
				maxv[o] = maxv[lc];
				nmax[lc] = nmax[lc] + nmax[rc];
			} else if(maxv[lc] > maxv[rc]) {//��>��
				maxv[o] = maxv[lc];
				nmax[o] = nmax[lc];
			} else {//��>��
				maxv[o] = maxv[rc];
				nmax[o] = nmax[rc];
			}
			//����minv
//			if(minv[o]>=minv[lc] && minv[o]>=minv[rc])
			if(minv[lc] == minv[rc]) {//��==��
				minv[o] = minv[lc];
				nmin[lc] = nmin[lc] + nmin[rc];
			} else if(minv[lc] > minv[rc]) {//��>��
				minv[o] = minv[rc];
				nmin[o] = nmin[rc];
			} else {//��>��
				minv[o] = minv[lc];
				nmin[o] = nmin[lc];
			}
		}
		maxv[o] += addv[o]; minv[o] += addv[o];
		sumv[o] += addv[o] * (R-L+1);
//		fprintf(fout, "maintian(o=%d, L=%d, R=%d) addv[%d]=%d, setv[%d]=%d, sumv[%d]=%d, maxv[%d]=%d, minv[%d]=%d, nmax[%d]=%d, nmin[%d]=%d\n", o, L, R, o, addv[o], o, setv[o], o, sumv[o], o, maxv[o], o, minv[o], o, nmax[o], o, nmin[o]);
	}
	void pushdown(int o) {//���´���
		int lc = o*2, rc = o*2+1;
		if(setv[o] >= 0) {
			setv[lc] = setv[rc] = setv[o]; 
			addv[lc] = addv[rc] = 0;
			setv[o] = -1;
		}
		if(addv[o] > 0) {
			addv[lc] += addv[o];
			addv[rc] += addv[o];
			addv[o] = 0;
		}
	}
	void add(int o, int L, int R, int v) {//o��ǰ�ڵ�,A[L-R]ÿ�����Ǯ����v
		int lc = o*2, rc = o*2+1;
		if(L>=oL && R<=oR) {
			addv[o] += v;
//			fprintf(fout, "add(o=%d, L=%d, R=%d, v=%d) addv[%d]=%d\n", o, L, R, v, o, addv[o]);
		} else {
			pushdown(o);
			int M = L + (R-L)/2;
			if(M >= oL) add(lc, L, M, v); else maintain(lc, L, M);
			if(M < oR) add(rc, M+1, R, v); else maintain(rc, M+1, R);
		}
		maintain(o, L, R);
	}
	/*
	void pushdown(int o) {
		int lc = o*2, rc = o*2+1;
		if(setv[o] >= 0) {
			setv[lc] = setv[rc] = setv[o];
			setv[o] = -1;
		}
	}
	*/
	void update(int p, int v, int o, int L, int R) {//A[p]=v;
		if(L == R) {
			sumv[o] = maxv[o] = minv[o] = v;
			nmax[o] = nmin[o] = 1;
			addv[o] = 0; setv[o] = -1;
		} else {
			pushdown(o);
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			if(M >= p) {
//				if(setv[lc] >= 0) pushdown(lc);
				update(p, v, lc, L, M);
			} else {
//				if(setv[rc] >= 0) pushdown(rc);
				update(p, v, rc, M+1, R);
			}
		}
		maintain(o, L, R);
	}
	void setmax(int o, int L, int R, int v) {//��A[oL]��A[oR]ÿ�����Ǯ����Ϊmax(A[i],v)
		if(L == R) {
			if(v > sumv[o]) {
//				if(setv[o] >= 0) pushdown(1);
				update(L, v, 1, 1, n);
			}
		} else {//��Ҷ�ڵ�
			int M = L + (R-L)/2;
			if(M >= oL) setmax(o*2, L, M, v);
			if(M < oR) setmax(o*2+1, M+1, R, v);
		}
	}
	void setmin(int o, int L, int R, int v) {//��A[oL]��A[oR]ÿ�����Ǯ����Ϊmin(A[i],v)
		if(L == R) {
			if(v < sumv[o]) {
//				if(setv[o] >= 0) pushdown(1);
				update(L, v, 1, 1, n);
			}
		} else {//��Ҷ�ڵ�
			int M = L + (R-L)/2;
			if(M >= oL) setmin(o*2, L, M, v);
			if(M < oR) setmin(o*2+1, M+1, R, v);
		}
	}
	void set(int o, int L, int R, int v) {//��A[oL]��A[oR]ÿ�����Ǯ����Ϊv
		if(L>=oL && R<=oR) {
			setv[o] = v; addv[o] = 0;
		} else {
			pushdown(o);
			int M = L + (R-L)/2;
			int lc = o*2, rc = o*2+1;
			if(M >= oL) set(lc, L, M, v); else maintain(lc, L, M);
			if(M < oR) set(rc, M+1, R, v); else maintain(rc, M+1, R);
		}
		maintain(o, L, R);
	}
	/*
	int qsum(int o, int L, int R) {//A[oL]��A[oR]ÿ�����Ǯ����
		maintain(o, L, R);
		///////
		if(setv[o] >= 0) {//set����Ӱ��
			fprintf(fout, "qsum(o=%d, L=%d, R=%d) case(setv[o=%d]>=0) return=%d\n", o, L, R, o, sumv[o]);
			return sumv[o];
		} else 
		if(L>=oL && R<=oR) {//�߽�
//			fprintf(fout, "qsum(o=%d, L=%d, R=%d) case((L=%d)>=(oL=%d) && (R=%d)<=(oR=%d)) return=%d\n", o, L, R, L, oL, R, oR, sumv[o]);
			return sumv[o];
		} else {
			pushdown(o);
			int M = L + (R-L)/2, ans = 0;
			if(M >= oL) ans += qsum(o*2, L, M); else maintain(o*2, L ,M);
			if(M < oR) ans += qsum(o*2+1, M+1, R); else maintain(o*2+1, M+1, R);
//			fprintf(fout, "qsum(o=%d, L=%d, R=%d) case(else) return=%d\n", o, L, R, ans);
			return ans;
		}
	}*/
	int qmax(int o, int L, int R) {//A[oL]��A[oR]ÿ�����Ǯ�������ֵ
		if(setv[o] >= 0) {//set����Ӱ��
			return maxv[o];
		} else if(L>=oL && R<=oR) {//�߽�
			return maxv[o];
		} else {
			int M = L + (R-L)/2, ans = 0;
			if(M >= oL) ans = max(ans, qmax(o*2, L, M));
			if(M < oR) ans = max(ans, qmax(o*2+1, M+1, R));
			return ans;
		}
	}
	int qmin(int o, int L, int R) {//A[oL]��A[oR]ÿ�����Ǯ������Сֵ
		if(setv[o] >= 0) {//set����Ӱ��
			return minv[o];
		} else if(L>=oL && R<=oR) {//�߽�
			return minv[o];
		} else {
			int M = L + (R-L)/2, ans = INF;
			if(M >= oL) ans = min(ans, qmin(o*2, L, M));
			if(M < oR) ans = min(ans, qmin(o*2+1, M+1, R));
			return ans;
		}
	}
	int qnmax(int o, int L, int R) {//A[oL]��A[oR]ÿ�����Ǯ�������ֵ�ĸ���
		if(setv[o] >= 0) {//set����Ӱ��
			return nmax[o];
		} else if(L>=oL && R<=oR) {//�߽�
			return nmax[o];
		} else {
			int M = L + (R-L)/2, ans = 0;
			if(M >= oL) ans += qnmax(o*2, L, M);
			if(M < oR) ans += qnmax(o*2+1, M+1, R);
			return ans;
		}
	}
	int qnmin(int o, int L, int R) {//A[oL]��A[oR]ÿ�����Ǯ������Сֵ�ĸ���
		if(setv[o] >= 0) {//set����Ӱ��
			return nmin[o];
		} else if(L>=oL && R<=oR) {//�߽�
			return nmin[o];
		} else {
			int M = L + (R-L)/2, ans = 0;
			if(M >= oL) ans += qnmin(o*2, L, M);
			if(M < oR) ans += qnmin(o*2+1, M+1, R);
			return ans;
		}
	}
	int qsum(int o, int L, int R) {
		maintain(o, L, R);
		if(L>=oL && R<=oR) {//�߽� 
			return sumv[o];
		} else {
			int lc = o*2, rc = o*2+1;
			pushdown(o);
			int M = L + (R-L)/2;
			int ans = 0;
			if(M >= oL) ans += qsum(lc, L, M); else maintain(lc, L ,M);
			if(M < oR) ans += qsum(rc, M+1, R); else maintain(rc, M+1, R);
			return ans;
		}
	}
	void execute_commands() {
		char buf[20];
		int op;
		fscanf(fin, "%s", buf);
		for(int i = 0; i < 9; i++) if(strcmp(buf, cmds[i]) == 0) {op = i; break;}
		int l, r, a, ans;
		switch(op) {
			case 0:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r;
				add(1, 1, n, a);//��A[l]��A[r]ÿ�����Ǯ����a
				break;
			case 1:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r;
				set(1, 1, n ,a);//��A[l]��A[r]ÿ�����Ǯ����Ϊa
				break;
			case 2:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r;
				setmax(1, 1, n, a);//��A[l]��A[r]ÿ�����Ǯ����Ϊmax(A[i],a)
				break;
			case 3:
				fscanf(fin, "%d%d%d", &l, &r, &a);
				oL = l; oR = r;
				setmin(1, 1, n, a);//��A[l]��A[r]ÿ�����Ǯ����Ϊmin(A[i],a)
				break;
			case 4:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qsum(1, 1, n);//���A[l]��A[r]ÿ�����Ǯ����
//				ans = 0;
//				qsum(1, 1, n, ans);
				fprintf(fout, "%d\n", ans);
				break;
			case 5:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qmax(1, 1, n);//��A[l]��A[r]ÿ�����Ǯ�������ֵ
				fprintf(fout, "%d\n", ans);
				break;
			case 6:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qmin(1, 1, n);//��A[l]��A[r]ÿ�����Ǯ������Сֵ
				fprintf(fout, "%d\n", ans);
				break;
			case 7:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qnmax(1, 1, n);//��A[l]��A[r]ÿ�����Ǯ�������ֵ�ĸ���
				fprintf(fout, "%d\n", ans);
				break;
			case 8:
				fscanf(fin, "%d%d", &l, &r);
				oL = l; oR = r;
				ans = qnmin(1, 1, n);//��A[l]��A[r]ÿ�����Ǯ������Сֵ�ĸ���
				fprintf(fout, "%d\n", ans);
				break;
		}
	}
};
int main() {
	fin = fopen("redbag.in", "r");
	fout = fopen("redbag.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) fscanf(fin, "%d", &A[i]);
	SEG *D = new SEG(n);
	fscanf(fin, "%d", &m);
	for(int i = 1; i <= m; i++) D->execute_commands();
	return 0;
}
