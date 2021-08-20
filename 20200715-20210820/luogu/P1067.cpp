#include <cstdio>

int n, t;
bool first = true;

int main() {
	scanf("%d", &n);
	for(int i=0, j=n; i <= n; i++, j--) {
		scanf("%d", &t);
		if(t == 0) continue;
		if(first) {
			first = false;
			if(j == 0) printf("%d", t);
			else if(j == 1) {
				if(t == 1) printf("x");
				else if(t == -1) printf("-x");
				else if(t > 0) printf("%dx", t);
				else printf("%dx", t);
			} else {
				if(t == 1) printf("x");
				else if(t == -1) printf("-x");
				else printf("%dx", t);
				printf("^%d", j);
			}
		} else {
			if(j == 0) {
				if(t > 0) printf("+%d", t);
				else printf("%d", t);
			} else if(j == 1) {
				if(t == 1) printf("+x");
				else if(t == -1) printf("-x");
				else if(t > 0) printf("+%dx", t);
				else printf("%dx", t);
			} else {
				if(t == 1) printf("+");
				else if(t == -1) printf("-");
				else {
					if(t > 0) printf("+%d", t);
					else printf("%d", t);
				}
				printf("x^%d", j);
			}
		}
	}
	return 0;
}
