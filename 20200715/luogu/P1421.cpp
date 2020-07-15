#include <cstdio>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	double d = a+b/10.0;
	printf("%d\n", (int)(d/1.90));
	return 0;
}
