#include <cstdio>
#include <cstring>

const int maxn = 1000+10;

int d[maxn];
int N, n=0, t;

int main() {
	memset(d, 0, sizeof(d));
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &t);
		d[t]++;
	}
	for(int i = 0; i <= 1000; i++) if(d[i]) n++;
	printf("%d\n", n);
	for(int i = 0; i <= 1000; i++) if(d[i]) printf("%d ", i);
	return 0;
}
