#include <cstdio>
#include <cctype>

const int maxn = 30;

char s[30];

int main() {
	scanf("%s", s);
	int ans=0, cnt=0;
	for(int i = 0; i < 11; i++) if(isdigit(s[i])) ans += (s[i]-'0')*++cnt;
	ans %= 11;
	if(ans==s[12]-'0' || (ans==10 && s[12]=='X')) printf("Right");
	else { s[12] = (ans==10)?'X':ans+'0'; printf("%s", s); }
	return 0;
}
