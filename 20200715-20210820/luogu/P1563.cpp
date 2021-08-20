#include <cstdio>

const int maxn = 100000+10;

int n, m, cnt=0;
int pos[maxn];
char job[maxn][12];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d%s", &pos[i], job[i]);
	for(int i = 0; i < m; i++) {
		int cmd, dis;
		scanf("%d%d", &cmd, &dis);
		int detla = -1;//0 0
		if(pos[cnt]) detla *= -1;
		if(cmd) detla *= -1;
		cnt += detla*dis;
		cnt %= n;
		while(cnt < 0) cnt += n;
	}
	printf("%s\n", job[cnt]);
	return 0;
}
