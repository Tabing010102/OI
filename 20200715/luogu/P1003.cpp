#include <cstdio>

const int maxn = 10000+10;

int d[maxn][4], n, tx, ty, ans=-1;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d%d%d", &d[i][0], &d[i][1], &d[i][2], &d[i][3]);
	scanf("%d%d", &tx, &ty);
	for(int i = 0; i < n; i++)
		if(tx>=d[i][0] && tx<=d[i][0]+d[i][2] && ty>=d[i][1] && ty<=d[i][1]+d[i][3])
			ans = i+1;
	printf("%d\n", ans);
	return 0;
}
