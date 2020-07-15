#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = i; j < n; j++) putchar(' ');
		for(int j = 0; j < i*2-1; j++) putchar('*');
		putchar('\n');
	}
	return 0;
}
