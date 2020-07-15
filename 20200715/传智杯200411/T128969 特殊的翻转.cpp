#include <cstdio>
#include <cstring>

const int maxn = 4e6+10;
const int maxn2 = 1e6+10;

char s[maxn2];
bool d[maxn];
bool d2[maxn];
int len, step=0;
int ans = 0x7fffffff;
int n=0;

void re(int p) {
	if(p != 1) d2[p-1] = !d2[p-1];
	d2[p] = !d2[p];
	if(p != n) d2[p+1] = !d2[p+1];
	step++;
}

int min(int a, int b) { return a<b?a:b; }

void proc(int &a, char c) {
	if(c == '0') { d[a] = 0; d[a+1] = 0; d[a+2] = 0; d[a+3] = 0; }
	else if(c == '1') { d[a] = 0; d[a+1] = 0; d[a+2] = 0; d[a+3] = 1; }
	else if(c == '2') { d[a] = 0; d[a+1] = 0; d[a+2] = 1; d[a+3] = 0; }
	else if(c == '3') { d[a] = 0; d[a+1] = 0; d[a+2] = 1; d[a+3] = 1; }
	else if(c == '4') { d[a] = 0; d[a+1] = 1; d[a+2] = 0; d[a+3] = 0; }
	else if(c == '5') { d[a] = 0; d[a+1] = 1; d[a+2] = 0; d[a+3] = 1; }
	else if(c == '6') { d[a] = 0; d[a+1] = 1; d[a+2] = 1; d[a+3] = 0; }
	else if(c == '7') { d[a] = 0; d[a+1] = 1; d[a+2] = 1; d[a+3] = 1; }
	else if(c == '8') { d[a] = 1; d[a+1] = 0; d[a+2] = 0; d[a+3] = 0; }
	else if(c == '9') { d[a] = 1; d[a+1] = 0; d[a+2] = 0; d[a+3] = 1; }
	else if(c == 'A') { d[a] = 1; d[a+1] = 0; d[a+2] = 1; d[a+3] = 0; }
	else if(c == 'B') { d[a] = 1; d[a+1] = 0; d[a+2] = 1; d[a+3] = 1; }
	else if(c == 'C') { d[a] = 1; d[a+1] = 1; d[a+2] = 0; d[a+3] = 0; }
	else if(c == 'D') { d[a] = 1; d[a+1] = 1; d[a+2] = 0; d[a+3] = 1; }
	else if(c == 'E') { d[a] = 1; d[a+1] = 1; d[a+2] = 1; d[a+3] = 0; }
	else { d[a] = 1; d[a+1] = 1; d[a+2] = 1; d[a+3] = 1; }
	a += 4;
}

int main() {
	scanf("%s", s);
	len = strlen(s);
	int cntp = 1;
	if(s[0] == '0') { cntp = 2; d[1] = 0; }
	else if(s[0] == '1') { cntp = 2; d[1] = 1; }
	else if(s[0] == '2') { cntp = 3; d[1] = 1; d[2] = 0; }
	else if(s[0] == '3') { cntp = 3; d[1] = 1; d[2] = 1; }
	else if(s[0] == '4') { cntp = 4; d[1] = 1; d[2] = 0; d[3] = 0; }
	else if(s[0] == '5') { cntp = 4; d[1] = 1; d[2] = 0; d[3] = 1; }
	else if(s[0] == '6') { cntp = 4; d[1] = 1; d[2] = 1; d[3] = 0; }
	else if(s[0] == '7') { cntp = 4; d[1] = 1; d[2] = 1; d[3] = 1; }
	else if(s[0] == '8') { cntp = 5; d[1] = 1; d[2] = 0; d[3] = 0; d[4] = 0; }
	else if(s[0] == '9') { cntp = 5; d[1] = 1; d[2] = 0; d[3] = 0; d[4] = 1; }
	else if(s[0] == 'A') { cntp = 5; d[1] = 1; d[2] = 0; d[3] = 1; d[4] = 0; }
	else if(s[0] == 'B') { cntp = 5; d[1] = 1; d[2] = 0; d[3] = 1; d[4] = 1; }
	else if(s[0] == 'C') { cntp = 5; d[1] = 1; d[2] = 1; d[3] = 0; d[4] = 0; }
	else if(s[0] == 'D') { cntp = 5; d[1] = 1; d[2] = 1; d[3] = 0; d[4] = 1; }
	else if(s[0] == 'E') { cntp = 5; d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 0; }
	else { cntp = 5; d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 1; }
	for(int i = 1; i < len; i++) proc(cntp, s[i]);
	n = cntp-1;
	cntp = 1;
	if(d2[1] == 1) {
		memcpy(d2, d, sizeof(d));
		re(1);
		cntp = d2[2]==0?3:2;
		while(1) {
			if(cntp >= n) break;
			re(cntp+1);
			while(d2[cntp]==0 && cntp<=n) cntp++;
			if(cntp > n) break;
		}
		if(d2[n-1]==0 && d2[n]==0) ans = min(ans, step);
		
		step = 0;
		memcpy(d2, d, sizeof(d));
		re(2);
		while(d2[cntp]==0 && cntp<=n) cntp++;
		while(1) {
			if(cntp >= n) break;
			re(cntp+1);
			while(d2[cntp]==0 && cntp<=n) cntp++;
			if(cntp > n) break;
		}
		if(d2[n-1]==0 && d2[n]==0) ans = min(ans, step);
	} else {
		memcpy(d2, d, sizeof(d));
		step = 0;
		while(d2[cntp]==0 && cntp<=n) cntp++;
		while(1) {
			if(cntp >= n) break;
			re(cntp+1);
			while(d2[cntp]==0 && cntp<=n) cntp++;
			if(cntp > n) break;
		}
		if(d2[n-1]==0 && d2[n]==0) ans = min(ans, step);
	}
	if(ans >= 0x7fffffff) printf("No");
	else printf("%d", ans);
}
