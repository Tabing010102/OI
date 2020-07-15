#include <cstdio>

int d[10], cnt, ans=0;

int main() {
	for(int i = 0; i < 10; i++) scanf("%d", &d[i]);
	scanf("%d", &cnt); cnt += 30;
	for(int i = 0; i < 10; i++) if(cnt >= d[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
