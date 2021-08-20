#include <cstdio>

int d[7], max=0, maxp;

int main() {
	for(int i = 0; i < 7; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		d[i] = t1+t2;
		if(d[i] > max) max=d[i], maxp=i;
	}
	if(max <= 8) printf("0\n");
	else printf("%d\n", maxp+1);
	return 0;
}
