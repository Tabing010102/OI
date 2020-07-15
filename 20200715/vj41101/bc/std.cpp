#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a==1 && b==0 && c==0) printf("Yes\n0");
	else {
		if(a <= b+c) printf("No");
		else printf("Yes\n%d", (b+c)*2+1);
	}
	return 0;
}
