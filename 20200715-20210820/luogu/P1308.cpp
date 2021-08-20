#include <cstdio>
#include <cstring>

const int maxn = 1000000+10;

char str[maxn], s[15];
int cnt, first=-1, count=0, len, len1;

char tolower(char c) { return (c>='A'&&c<='Z')?c-'A'+'a':c; }

int main() {
	gets(s);
	len1 = strlen(s);
	for(int i = 0; i < len1; i++) s[i] = tolower(s[i]);
	gets(str);
	len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] == ' ') while(str[i] != ' ') i++;
		if(s[0] == tolower(str[i])) {
			bool failed = false;
			for(int j = 0; j < len1; j++) if(s[j] != tolower(str[i+j])) { failed = true; break; }
			if(str[i+len1] != ' ') failed = true;
			if(!failed) {
				if(first == -1) first = i;
				count++;
			}
			while(i<len && str[i]!=' ') i++;
		} else {
			while(i<len && str[i]!=' ') i++;
		}
	}
	if(count == 0) printf("-1\n");
	else printf("%d %d\n", count, first);
	return 0;
}
