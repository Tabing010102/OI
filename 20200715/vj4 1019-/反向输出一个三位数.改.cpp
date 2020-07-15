#include <cstdio>

int main() {
	int n, a, b, ans=0;
	scanf("%d", &n);
	a = n%10; n /= 10;
	b = n%10; n /= 10;
	ans = a*100+b*10+n;
	printf("%d\n", ans);
}
