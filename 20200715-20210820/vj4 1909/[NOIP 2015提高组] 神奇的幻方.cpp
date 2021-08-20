#include <cstdio>

int n, d[40][40], x, y;

int main() {
	scanf("%d", &n); d[x=1][y=n/2+1] = 1;
	for(int i = 2; i <= n*n; i++) {
		if(x==1 && y!=n) d[x=n][++y] = i;
		else if(y==n && x!=1) d[--x][y=1] = i;
		else if(x==1 && y==n) d[++x][y] = i;
		else if(x!=1 && y!=n) {
			if(d[x-1][y+1] == 0) d[--x][++y] = i;
			else d[++x][y] = i;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) printf("%d ", d[i][j]);
		printf("\n");
	}
	return 0;
}
