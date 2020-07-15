#include <cstdio>

const int maxn = 100+10;

int n, d[maxn], ans=0;
bool vis[20000+10];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &d[i]);
	for(int i = 0; i < n-1; i++) for(int j = i+1; j < n; j++) {
		int tans = d[i]+d[j];
		if(vis[tans]) continue;
		else vis[tans] = true;
		bool found = false;
		for(int k = 0; k < n; k++) if(d[k]==tans && k!=i && k!=j) found = true;
		if(found) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
