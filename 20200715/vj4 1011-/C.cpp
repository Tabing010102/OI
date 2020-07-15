#include <cstdio>
#include <cstring>

const int maxn = 200000+10;

int q, n;
char l[2][maxn];
bool ok;

//1×ó, 3ÉÏ, 4ÏÂ 
void dfs(int line, int col, int last) {
	//printf("dfs(line=%d, col=%d, last=%d)\n", line, col, last);
	if(col==n && line==0) return;
	if(col==n && line==1) { ok = true; return; }
	if(l[line][col]=='1' || l[line][col]=='2') {
		if(last==3 || last==4) return;
		dfs(line, col+1, last);
	} else {
		if(last == 1) {
			if(line == 0) dfs(1, col, 3);
			else dfs(0, col, 4);
		} else if(last == 3) dfs(1, col+1, 1);
		else if(last == 4) dfs(0, col+1, 1);
	}
}

int main() {
	scanf("%d", &q);
	while(q--) {
		memset(l, 0, sizeof(l)); ok = false;
		scanf("%d", &n);
		scanf("%s%s", l[0], l[1]);
		dfs(0, 0, 1);
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
