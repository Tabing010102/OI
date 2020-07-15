#include <cstdio>

const int maxn = 1000000+10;

int n, k;
char ori[maxn], target[maxn];

void reverse(int pos) {
	for(int i=0, j=pos; i < k; i++, j++)
		ori[j] = ori[j]=='1'?'0':'1';
}

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s%s", ori, target);
	for(int i = 0; i < n-k+1; i++) {
		if(ori[i] == target[i]) continue;
		else reverse(i);
	}
	bool ok = true;
	for(int i = n-k+1; i < n; i++) if(ori[i] != target[i]) { ok = false; break; }
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}
