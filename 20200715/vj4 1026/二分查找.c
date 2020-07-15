#include <stdio.h>

#define MAXN 2000000+10

int n, m, d[MAXN];
int i, L, R, M, t;

int main() {
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) scanf("%d", &d[i]);
	for(i = 0; i < m; i++) {
		scanf("%d", &t);
		L = 0; R = n-1;
		while(L < R) {
			M = L + (R-L)/2;
			if(d[M] == t) L = R = M;
			else if(d[M] > t) L = M+1;
			else R = M-1;
		}
		if(d[L] == t) printf("%d\n", L+1);
		else printf("none\n");
	}
	return 0;
}
