#include <fstream>
#include <string>
using namespace std;
typedef long long LL;
const LL maxn = 100000+10;
fstream fin, fout;
LL n, m, A[maxn];
struct SEG {
	LL sumv[maxn*4], addv[maxn*4];
	SEG(LL k) {
		build(1, 1, k);
	}
	void mAintain(LL o, LL L, LL R) {
		LL lc=o*2, rc=o*2+1;
		if(R > L) sumv[o] = sumv[lc]+sumv[rc];
		//必须加这句 
		else sumv[o] = A[L];
		//必须加这句 
		if(addv[o]) sumv[o] += addv[o]*(R-L+1);
	}
	void build(LL o, LL L, LL R) {
		addv[o] = 0;
		if(L == R) {
			sumv[o] = A[L];
		} else {
			LL lc=o*2, rc=o*2+1;
			LL M = L + (R-L)/2;
			build(lc, L, M);
			build(rc, M+1, R);
			mAintain(o, L, R);
		}
	}
	LL oL, oR, av;
	void add(LL o, LL L, LL R) {
		if(L>=oL && R<=oR) {
			addv[o] += av;
		} else {
			LL lc=o*2, rc=o*2+1;
			LL M = L + (R-L)/2;
			if(M >= oL) add(lc, L, M);
			if(M < oR) add(rc, M+1, R);
		}
		mAintain(o, L, R);
	}
	LL _sum;
	void qsum(LL o, LL L, LL R, LL _add=0) {
		if(L>=oL && R<=oR) {
			_sum += sumv[o]+_add*(R-L+1);
		} else {
			LL lc=o*2, rc=o*2+1;
			LL M = L + (R-L)/2;
			if(M >= oL) qsum(lc, L, M, _add+addv[o]);
			if(M < oR) qsum(rc, M+1, R, _add+addv[o]);
		}
	}
	void execute_command() {
		string buf;
		fin >> buf;
		if(buf[0] == 'A') {
			fin >> oL >> oR >> av;
			add(1, 1, n);
		} else {
			fin >> oL >> oR;
			_sum = 0;
			qsum(1, 1, n);
			fout << _sum << endl;
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	fin.open("shuliec.in", ios::in);
	fout.open("shuliec.out", ios::out);
	fin >> n;
	for(LL i = 1; i <= n; i++) fin >> A[i];
	SEG *D = new SEG(n);
	fin >> m;
	for(LL i = 1; i <= m; i++) D->execute_command();
}
