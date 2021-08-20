#include <cstdio>
#include <cmath>

int n, k, d[25], ans=0;

bool is_prime(int n) {
	if(n == 1) return false;
	int sn = (int)sqrt(n)+1;
	bool flag = true;
	for(int i = 2; i <= sn; i++) {
		if(n%i==0 && n/i>1) {
			flag = false;
			break;
		}
	}
	if(flag) return true;
	else return false;
}

void pick(int cntp, int cnt, int dep) {
	if(dep == k+1) {
		if(is_prime(cnt)) ans++;
	} else {
		for(int i = cntp+1; i < n-(k-dep); i++) pick(i, cnt+d[i], dep+1);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &d[i]);
	for(int i = 0; i <= n-k; i++) pick(i, d[i], 2);
	printf("%d\n", ans);
	return 0;
}
