#include <stdio.h>
#include <string.h>

#define MAXN 9+5

char s[MAXN], ans[MAXN];
int d[26], len, i;

void dfs(int dep) {
	if(dep >= len) { int i; for(i = 0; i < len; i++) putchar(ans[i]); putchar('\n'); return; }
	else {
		int i;
		for(i = 0; i < 26; i++) if(d[i]) {
			ans[dep] = i+'a'; d[i]--;
			dfs(dep+1);
			d[i]++;
		}
	}
}

int main() {
	scanf("%s", s);
	len = strlen(s);
	for(i = 0; i < len; i++) d[s[i]-'a']++;
	memset(ans, 0, sizeof(ans));
	dfs(0);
	return 0;
}
