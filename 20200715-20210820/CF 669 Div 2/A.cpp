#include <cstdio>
#include <cstring>

const int maxn = 1000+10;

int d[maxn];
int n, T, n0, n1, t0, t0n1;
bool first;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		n0 = n1 = 0; first = true;
		for(int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			if(t == 0) n0++;
			if(first && t==0) { t0=i; t0n1=n1; first=false; }
			if(t == 1) n1++;
		}
		if(n0 >= n1) {
				printf("%d\n", n0);
				for(int j = 0; j < n0; j++) printf("0 ");
				printf("\n");
			} else if(n1-n0==1 && n1%2==1) {
				printf("%d\n", n1);
				if(t0n1%2 == 1) {
					for(int i = 0; i < t0n1-1; i++) printf("1 ");
					printf("0 ");
					for(int i = t0n1+1; i < n; i++) printf("1 ");
				} else {
					for(int i = 0; i < t0n1; i++) printf("1 ");
					printf("0 ");
					for(int i = t0n1+1; i < n-1; i++) printf("1 ");
				}
				printf("\n");
			} else {
				if(n1%2 == 1) n1--;
				printf("%d\n", n1);
				for(int j = 0; j < n1; j++) printf("1 ");
				printf("\n");
			}
	}
	return 0;
}
