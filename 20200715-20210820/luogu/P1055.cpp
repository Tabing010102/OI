#include <cstdio>

char s[20];
int d[10];

int main() {
	scanf("%s", s);
	for(int i=0, j=0; i < 11; i++) {
		if(s[i] == '-') continue;
		d[j++] = s[i]-'0';
	}
	int x = 0;
	for(int i = 0; i < 9; i++) x += d[i]*(i+1);
	x %= 11;
	if(x == 10) {
		if(s[12] == 'X') printf("Right");
		else {
			s[12] = 'X';
			printf("%s\n", s);
		}
	} else {
		if(s[12] == x+'0') printf("Right");
		else {
			s[12] = x+'0';
			printf("%s\n", s);
		}
	}
	return 0;
}
