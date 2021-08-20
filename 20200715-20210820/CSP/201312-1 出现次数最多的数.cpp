#include <cstdio>

const int maxn = 10000+10;

int n, t, maxv, maxc=0;
int d[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) { scanf("%d", &t); d[t]++; }
	for(int i = 1; i <= 10000; i++) if(d[i] > maxc) { maxc = d[i]; maxv = i; }
	printf("%d\n", maxv);
	return 0;
}
