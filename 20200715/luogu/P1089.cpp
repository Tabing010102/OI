#include <cstdio>
#include <cstdlib>

int store=0, left=0;

int main() {
	for(int i = 1; i <= 12; i++) {
		int t;
		scanf("%d", &t);
		if(t > left+300) { printf("%d\n", -i); exit(0); }
		else {
			store += (left+300-t)/100*100;
			left = left+300-(left+300-t)/100*100-t;
		}
		//printf("store=%d, left=%d, t=%d\n", store, left, t);
	}
	printf("%.0lf\n", store*1.2+left);
	return 0;
}
