#include <cstdio>
#include <cstdlib>

const int maxn = 1000000+10;

char s[maxn], t[maxn];
int ls, lt;

int main() {
	scanf("%d%d", &ls, &lt);
	fflush(stdin);
	gets(s);
	gets(t);
	bool flag = false;
	if(lt > ls) printf("-1");
	else {
		for(int i = 0; i < ls-lt+1; i++) {
			flag = true;
			for(int j = 0; j < lt; j++) {
				if(t[j] < s[i+j]) break;
				if(t[j] > s[i+j]) { flag = false; break; }
				if(i==ls-lt && t[j]==s[i+j]) {flag = false; break; }
			}
			if(flag) { printf("%d", ls-i); exit(0); }
		}
	}
	printf("-1");
	return 0;
}
