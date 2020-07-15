#include <stdio.h>

int main() {
	int n; scanf("%d", &n);
	double ans = 1.0;
	int i; double cnt;
	for(i = 2; i <= n; i++) {
		cnt = 1.0/i;
		if(i%2 == 0) ans -= cnt;
		else ans += cnt;
	}
	printf("%.2lf\n", ans);
	return 0;
}
