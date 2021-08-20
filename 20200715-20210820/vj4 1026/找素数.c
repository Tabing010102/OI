#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXN 2000000+10

int vis[MAXN];

int main() {
	int beg, end; scanf("%d%d", &beg, &end);
	int m = sqrt(end+0.5);
	memset(vis, 0, sizeof(vis)); vis[1] = 1;
	int i, j;
	for(i = 2; i <= m; i++) if(!vis[i])
		for(j = i*i; j <= end; j += i) vis[j] = 1;
	int cnt = 0;
	for(i = beg; i <= end; i++) if(!vis[i]) {
		cnt++;
		printf("%d ", i);
		if(cnt == 5) { cnt = 0; printf("\n"); }
	}
	return 0;
}
