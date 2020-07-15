#include <cstdio>

int n, ans[4];

bool get(int n) {
	if(n%7 == 0) return true;
	while(n) {
		int cnt = n%10;
		if(cnt == 7) return true;
		n /= 10;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		if(get(i)) { ans[(i-1)%4]++; n++; }
	for(int i = 0; i < 4; i++) printf("%d\n", ans[i]);
	return 0;
}
