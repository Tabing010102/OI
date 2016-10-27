#include <cstdio>
using namespace std;
const int maxn = 100000+100;
const int INF = 0x3f3f3f3f;
FILE *fin, *fout;
int n, d[maxn], ans=0, tot=0;
int qz[maxn];
inline int min(int a, int b) { return a<b?a:b; }
int main() {
	fin = fopen("circle.in", "r");
	fout = fopen("circle.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%d", &d[i]);
		tot += d[i];
		qz[i] = qz[i-1] + d[i];
	}
//	fprintf(fout, "d, qz, hz\n");
//	for(int i = 1; i <= n; i++) fprintf(fout, "%d %d %d\n", d[i], qz[i], hz[i]);
	for(int i = 1; i <= n; i++) for(int j = i+1; j <= n; j++) {
		int tmp = INF;
		tmp = min(tmp, qz[j-1]-qz[i-1]);
		tmp = min(tmp, tot-tmp);
		if(tmp > ans) ans = tmp;
	}
	fprintf(fout, "%d\n", ans);
	return 0;
}
