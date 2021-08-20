#include <stdio.h>

int T, n, i, ans;

void dfs(int last, int lft) {
	//printf("dfs(last=%d, lft=%d)\n", last, lft);
	if(lft==1) { ans++; return; }
	else {
		int i;
		for(i = last; i <= lft; i++) if(lft%i == 0) dfs(i, lft/i);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ans = 0;
		for(i = 2; i <= n; i++) if(n%i == 0) dfs(i, n/i);
		printf("%d\n", ans);
	}
	return 0;
}
