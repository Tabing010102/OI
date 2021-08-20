#include <cstdio>

const int maxn = 100+10;

int n, d[maxn], ans[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &d[i]);
	for(int i = 0; i < n; i++)
		for(int j = i-1; j >= 0; j--)
			if(d[j] < d[i]) ans[i]++;
	for(int i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}
