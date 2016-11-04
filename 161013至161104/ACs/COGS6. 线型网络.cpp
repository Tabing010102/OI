#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 20+5;
const double INF = 1e7;
FILE *fin, *fout;
int n, orders[maxn];
int p[maxn][2];
double d[maxn][maxn];
double ans = INF;
inline double dis(int a, int b) {
	return sqrt((p[a][0] - p[b][0])*(p[a][0] - p[b][0]) + (p[a][1] - p[b][1])*(p[a][1] - p[b][1]));
}
inline double min(double a, double b) { return a<b?a:b; }
void reserve(int L, int R) {
	while(L < R) {
		swap(orders[L], orders[R]);
		L++; R--;
	}
}
int main() {
	srand(time(NULL));
	fin = fopen("linec.in", "r");
	fout = fopen("linec.out", "w");
//	fout = stdout;
	fscanf(fin ,"%d", &n);
	for(int i = 0; i < n; i++) { fscanf(fin, "%d%d", &p[i][0], &p[i][1]); orders[i]=i; }
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		d[i][j] = dis(i, j);
//		fprintf(fout, "d[i=%d][j=%d] = %.2lf\n", i, j, d[i][j]);
	}
	for(int i = 1; i <= 10000; i++) {//随机化次数 
//		for(int j = 0; j < n; j++) fprintf(fout, "%d ", orders[j]);
//		fprintf(fout, "\n");
		//随机化 
		for(int j = 1; j <= 100; j++) swap(orders[rand()%n], orders[rand()%n]); 
		//贪心 
		for(int a = 1; a < n; a++) for(int b = a; b < n-1; b++)
		if(d[orders[a]][orders[a-1]]+d[orders[b]][orders[b+1]] > d[orders[a-1]][orders[b]]+d[orders[a]][orders[b+1]])
		reserve(a, b);
//		for(int j = 0; j < n; j++) fprintf(fout, "%d ", orders[j]);
		double tmp = 0;
		for(int j = 0; j < n-1; j++) tmp += d[orders[j]][orders[j+1]];
//		fprintf(fout, "%.2lf\n", tmp);
		ans = min(ans, tmp);
	}
	fprintf(fout, "%.2lf\n", ans);
	return 0;
}
