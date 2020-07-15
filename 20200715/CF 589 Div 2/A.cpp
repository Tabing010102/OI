#include <cstdio>
#include <cstring>

int l, r, cnt;
bool ok = false;
bool vis[10];

bool check(int n) {
	memset(vis, 0, sizeof(vis));
	while(n) {
		cnt = n%10;
		if(vis[cnt]) return false;
		vis[cnt] = true;
		n /= 10;
	}
	return true;
}

int main() {
	scanf("%d%d", &l, &r);
	for(int i = l; i <= r; i++) {
		if(check(i)) { ok = true; printf("%d\n", i); break; }
		else continue;
	}
	if(!ok) printf("-1\n");
	return 0;
}
