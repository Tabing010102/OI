#include <stdio.h>

typedef long long LL;

const LL MOD = 1e9+7;

LL pow_mod(LL a, LL n, LL m) {//(a^n) % m
	if(n == 0) return 1;
	LL x = pow_mod(a, n/2, m);
	LL ans = (LL)x * x % m;
	if(n%2 == 1) ans = ans * a % m;
	return ans;
}

LL n;

int main() {
	scanf("%lld", &n);
	printf("%lld", pow_mod(2, n, MOD));
	return 0;
}
