#include <cstdio>

int n, x, ans=0;

int main() {
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) {
		int t = i;
		while(t) {
			int tt = t%10;
			if(tt == x) ans++;
			t /= 10;
		}
	}
	printf("%d\n", ans);
	return 0;
}
