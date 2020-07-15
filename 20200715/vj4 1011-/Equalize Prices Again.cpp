#include <cstdio>

int q, n, tot;

int main() {
	scanf("%d", &q);
	while(q--) {
		tot = 0;
		scanf("%d", &n);
		int t;
		for(int i = 0; i < n; i++) { scanf("%d", &t); tot += t; }
		if(tot%n) printf("%d\n", tot/n+1);
		else printf("%d\n", tot/n);
	}
	return 0;
}
