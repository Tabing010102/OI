#include <cstdio>

int main() {
	double target;
	scanf("%lf", &target);
	double cnt=2.0, cntp=0.0;
	int step=0;
	while(cntp < target) {
		step++;
		cntp += cnt;
		cnt *= 0.98;
	}
	printf("%d\n", step);
	return 0;
}
