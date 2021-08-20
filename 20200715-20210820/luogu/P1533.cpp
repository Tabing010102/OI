#include <cstdio>
#include <cstring>

char s[25];
int len, type=0;

int main() {
	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(s[i] == '.') { type = 1; break; }
		if(s[i] == '/') { type = 2; break; }
		if(s[i] == '%') { type = 3; break; }
	}
	if(type == 0) {
		int cnt = len-1;
		while(cnt>0 && s[cnt]=='0') cnt--;
		for(int i = cnt; i >= 0; i--) putchar(s[i]);
	} else if(type == 1) {
		int t = 0;
		while(s[t] != '.') t++;
		int cnt = t-1;
		while(cnt>0 && s[cnt]=='0') cnt--;
		for(int i = cnt; i >= 0; i--) putchar(s[i]);
		putchar('.');
		int t1 = t+1;
		while(s[t1] == '0') t1++;
		cnt = len-1;
		while(cnt>t && s[cnt]=='0') cnt--;
		for(int i = cnt; i >= t1; i--) putchar(s[i]);
		if(t1 > cnt) putchar('0');
	} else if(type == 2) {
		int t = 0;
		while(s[t] != '/') t++;
		int cnt = t-1;
		while(cnt>0 && s[cnt]=='0') cnt--;
		for(int i = cnt; i >= 0; i--) putchar(s[i]);
		putchar('/');
		cnt = len-1;
		while(cnt>t+1 && s[cnt]=='0') cnt--;
		for(int i = cnt; i > t; i--) putchar(s[i]);
	} else {
		int cnt = len-2;
		while(cnt>0 && s[cnt]=='0') cnt--;
		for(int i = cnt; i >= 0; i--) putchar(s[i]);
		putchar('%');
	}
	return 0;
}
