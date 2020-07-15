#include <cstdio>
#include <cstring>

const int maxL = 10000+10;

int L, M, ans=0;
bool vis[maxL];

int main() {
	scanf("%d%d", &L, &M);
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < M; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		for(int j = t1; j <= t2; j++) vis[j] = true;
	}
	for(int i = 0; i <= L; i++) if(!vis[i]) ans++;
	printf("%d\n", ans);
	return 0;
}
