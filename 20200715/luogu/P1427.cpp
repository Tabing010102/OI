#include <cstdio>

const int maxn = 100+10;

int d[maxn], cnt=0;

int main() {
	int t;
	while(scanf("%d", &t) == 1) {
		if(t == 0) break;
		d[++cnt] = t;
	}
	for(int i = cnt; i > 0; i--) printf("%d ", d[i]);
	return 0;
}
