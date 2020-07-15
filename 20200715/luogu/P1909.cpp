#include <cstdio>

const int INF = 0x7fffffff;

int n, d[3], w[3], ans=INF;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 3; i++) scanf("%d%d", &d[i], &w[i]);
	for(int i = 0; i < 3; i++) {
		int t = n/d[i];
		if(n%d[i] != 0) t++;
		int tans = t*w[i];
		if(tans < ans) ans = tans;
	}
	printf("%d\n", ans);
	return 0;
}
