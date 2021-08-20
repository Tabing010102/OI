#include <cstdio>
#include <cstring>

int n, ans=0, d[1010];

int dfs(int cnt) {
	if(d[cnt] != -1) return d[cnt];
	int tans = 1;
	for(int i = 1; i <= cnt/2; i++) tans += dfs(i);
	return d[cnt]=tans;
}

int main() {
	scanf("%d", &n);
	memset(d, -1, sizeof(d));
	printf("%d\n", dfs(n));
	return 0;
}
