#include <cstdio>

int x, n, ans=0;

int main() {
	scanf("%d%d", &x, &n);
	ans += 250*((x>5)?0:6-x);
	if(n > 8-x) {
		n -= 8-x;
		ans += 1250*(n/7);
		n %= 7;
		ans += 250*((n>4)?5:n);
	}
	printf("%d\n", ans);
	return 0;
}
