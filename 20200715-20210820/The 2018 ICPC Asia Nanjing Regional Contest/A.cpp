#include <cstdio>

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	if(n == 0) printf("Austin\n");
	else if(k >= n) printf("Adrien\n");
	else if(n%2==0 && k==1) printf("Austin\n");
	else printf("Adrien\n");
	return 0;
}
