#include <cstdio>
//#include <algorithm>
//#include <cctype>
using namespace std;
const int maxn = 1000000+10;
//const int maxq = 7000+10;
int H[maxn], n, q, d[maxn][20];
//int Q[maxq][2];
FILE *fin, *fout;
int max(int a, int b) { return a<b?b:a; }
int min(int a, int b) { return a<b?a:b; }
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
void RMQ_init(int n) {
	for(int i = 0; i < n; i++) d[i][0] = H[i];
	for(int j = 1; (1<<j) <= n; j++) 
		for(int i = 0; i+(1<<j)-1 < n; i++)
			d[i][j] = max(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int RMQ(int L, int R) {
	int k = 0;
	while((1<<(k+1)) <= R-L+1) k++;
	return max(d[L][k], d[R-(1<<k)+1][k]);
}
int main() {
	fin = fopen("climb.in", "r");
	fout = fopen("climb.out", "w");
//	fout = stdout;
//	fscanf(fin, "%d", &n);
	n = Q_read();
//	for(int i = 0; i <= n; i++) fscanf(fin, "%d", &H[i]);
	for(int i = 0; i <= n; i++) H[i] = Q_read(); 
	RMQ_init(n+1);
//	fscanf(fin, "%d", &q);
	q = Q_read();
	for(int i = 1; i <= q; i++) {
		int a, b;
		a = Q_read(); b = Q_read();
//		fprintf(fout, "%d\n", RMQ(a, b));
		int c = RMQ(a, b);
		Q_write(c);
		fputc('\n', fout);
	}
	return 0;
}
