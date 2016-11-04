#include <cstdio>
#include <set>
using namespace std;
const int maxn = 2000+10;
int n, m, fa[2*maxn];
set<int> gr;
FILE *fin, *fout;
int find(int x) { return x == fa[x] ? x : fa[x]=find(fa[x]); }
int main() {
	fin = fopen("crime.in", "r");
	fout = fopen("crime.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= 2*n; i++) fa[i] = i;
//	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		char buf[10]; int a, b;
		fscanf(fin, "%s%d%d", buf, &a, &b);
		int f1 = find(a);
		int f2 = find(b);
		if(buf[0] == 'F') {
//			if(f1 == f2) cnt++;
			fa[f1] = fa[f2];
		} else {
			int _f1 = find(a+n);
			int _f2 = find(b+n);
//			if(f1 != f2) cnt++;
			fa[_f1] = f2;
			fa[_f2] = f1;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		int f = find(i);
		if(!gr.count(f)) { gr.insert(f); cnt++; }
	}
	fprintf(fout, "%d", cnt);
	return 0;
}
