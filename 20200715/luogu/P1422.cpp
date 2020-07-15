#include <cstdio>

int main() {
	int d; scanf("%d", &d);
	double ans=0;
	if(d <= 150) ans += d*0.4463;
	else {
		ans += 150*0.4463;
		if(d <= 400) ans += (d-150)*0.4663;
		else {
			ans += 250*0.4663;
			ans += (d-400)*0.5663;
		}
	}
	printf("%.1lf\n", ans);
	return 0;
}
