#include <cstdio>
#include <cstring>

bool vis[10];

int main() {
	for(int i = 123; i <= 333; i++) {
		memset(vis, 0, sizeof(vis));
		int t = i;
		int t1 = t/100; t %= 100; vis[t1] = true;
		int t2 = t/10; t %= 10;
		if(vis[t2] || t2==0) continue;
		vis[t2] = true;
		if(vis[t] || t==0) continue;
		vis[t] = true;
		
		t = i*2;
		t1 = t/100; t %= 100; vis[t1] = true;
		t2 = t/10; t %= 10;
		if(vis[t2] || t2==0) continue;
		vis[t2] = true;
		if(vis[t] || t==0) continue;
		vis[t] = true;
		
		t = i*3;
		t1 = t/100; t %= 100; vis[t1] = true;
		t2 = t/10; t %= 10;
		if(vis[t2] || t2==0) continue;
		vis[t2] = true;
		if(vis[t] || t==0) continue;
		vis[t] = true;
		
		printf("%d %d %d\n", i, i*2, i*3);
	}
	return 0;
}
