#include <stdio.h>
#include <string.h>

#define MAXN 30
#define DETLA 30

int n, l[MAXN], ans[MAXN], ansn=0, c1[MAXN+DETLA], c2[MAXN];
//c1左上-右下对角线，c2右上-左下对角线 

void dfs(int dep) {
	if(dep > n) {
		if(ansn < 3) { int i; for(i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n"); }
		ansn++; return;
	} else {
		int i;
		for(i = 1; i <= n; i++) {
			if(l[i] || c1[dep-i+DETLA] || c2[dep+i]) continue;
			l[i] = c1[dep-i+DETLA] = c2[dep+i] = 1; ans[dep] = i;
			dfs(dep+1);
			l[i] = c1[dep-i+DETLA] = c2[dep+i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(l, 0, sizeof(l));
	memset(ans, 0, sizeof(ans));
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	dfs(1);
	printf("%d\n", ansn);
	return 0;
}
