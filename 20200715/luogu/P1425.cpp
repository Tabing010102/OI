#include <cstdio>

int main() {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	e = c-a;
	if(b > d) e--, f=60-(b-d);
	else f = d-b;
	printf("%d %d\n", e, f);
	return 0;
}
