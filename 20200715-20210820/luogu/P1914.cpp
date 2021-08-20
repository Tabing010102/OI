#include <cstdio>
#include <cstring>

const int maxn = 50+5;

char s[maxn];
int n, d[maxn], l;

int main() {
	scanf("%d%s", &n, s);
	l = strlen(s);
	for(int i = 0; i < l; i++) d[i] = s[i]-'a';
	for(int i = 0; i < l; i++) d[i] = (d[i]+n)%26;
	for(int i = 0; i < l; i++) putchar(d[i]+'a');
	return 0;
}
