#include <cstdio>
#include <cstring>

char s[110];
int d[26], max=0;

int main() {
	for(int i = 0; i < 4; i++) {
		gets(s);
		int l = strlen(s);
		for(int j = 0; j < l; j++) {
			if(s[j]<'A' || s[j]>'Z') continue;
			d[s[j]-'A']++;
		}
	}
	for(int i = 0; i < 26; i++) if(d[i] > max) max = d[i];
	for(int i = max; i >= 1; i--) {
		for(int j = 0; j < 25; j++) {
			if(d[j] >= i) putchar('*');
			else putchar(' ');
			putchar(' ');
		}
		if(d[25] >= i) putchar('*');
		putchar('\n');
	}
	for(int i = 0; i < 25; i++) putchar(i+'A'), putchar(' '); putchar('Z');
	return 0;
}
