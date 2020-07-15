#include <cstdio>

int main() {
	int n, x, y, z, ans;
	scanf("%d%d%d", &n, &x, &y);
	z = y/x;
	if(y%x) z++;
	ans = n-z;
	if(ans < 0) ans = 0;
	printf("%d\n", ans);
	return 0;
}
