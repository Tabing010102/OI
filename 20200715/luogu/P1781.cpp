#include <cstdio>
#include <cstring>

const int bufsize = 100+10;

char ans[bufsize], ansr, buf[bufsize];
int n, anss, bufs;

void cz(const char *s, int r) {
	bufs = strlen(s);
	if(bufs < anss) return;
	else if(bufs > anss) {
		strcpy(ans, s);
		ansr = r;
		anss = bufs;
	} else {
		for(int i = 0; i < anss; i++)
			if(ans[i] > s[i]) return;
			else if(ans[i] == s[i]) continue;
			else {
				strcpy(ans, s);
				ansr = r;
				anss = bufs;
				return;
			}
	}
	return;
}

int main() {
	scanf("%d", &n);
	ansr = 1;
	scanf("%s", ans);
	anss = strlen(ans);
	for(int i = 2; i <= n; i++) {
		scanf("%s", buf);
		bufs = strlen(buf);
		cz(buf, i);
	}
	printf("%d\n%s", ansr, ans);
	return 0;
}
