#include <stdio.h>

#define MAXN 10000+10
#define INF 0x7fffffff

int d[MAXN], minv=INF, minp, maxv=-INF, maxp;

int main() {
	int n; scanf("%d", &n);
	int i; for(i = 0; i < n; i++) scanf("%d", &d[i]);
	for(i = 0; i < n; i++) {
		if(d[i] > maxv) { maxv = d[i]; maxp = i; }
		if(d[i] < minv) { minv = d[i]; minp = i; }
	}
	d[maxp] = minv; d[minp] = maxv;
	for(i = 0; i < n; i++) printf("%d ", d[i]);
	return 0;
}
