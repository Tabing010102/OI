#include <cstdio>
#include <cstdlib>

const int maxn = 100+5;
const int MOD = 1000000007;

bool G[maxn][maxn];
bool vG[maxn][maxn];
int r[maxn], c[maxn];
int h, w, pt=0;

int pow_mod(int a, int n, int m) {
	if(n == 0) return 1;
	int x = pow_mod(a, n/2, m);
	long long ans = (long long)x * x % m;
	if(n%2 == 1) ans = ans * a % m;
	return (int)ans;
}

int main() {
	scanf("%d%d", &h, &w);
	for(int i = 0; i < h; i++) {
		int t; scanf("%d", &t); r[i] = t;
		for(int j = 0; j < t; j++) G[i][j] = true;
	}
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) vG[i][j] = G[i][j];
	for(int i = 0; i < h; i++) vG[i][r[i]] = 1;
	
	for(int i = 0; i < w; i++) {
		int t; scanf("%d", &t); c[i] = t;
		for(int j = 0; j < t; j++) {
			if(G[j][i]==0 && vG[j][i]==1) { printf("0\n"); exit(0); }
			vG[j][i] = G[j][i] = true;
		}
	}
	for(int i = 0; i < w; i++) {
		if(G[c[i]][i]==1) { printf("0\n"); exit(0); }
		vG[c[i]][i] = 1;
	}
	/*
	printf("G:\n");
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) printf("%d ", G[i][j]);
		printf("\n");
	}
	
	printf("vG:\n");
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) printf("%d ", vG[i][j]);
		printf("\n");
	}
	*/
	for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) if(!vG[i][j]) pt++;
	//printf("pt=%d\n", pt);
	//if(pt == 0) printf("0\n");
	printf("%d\n", pow_mod(2, pt, MOD));
	return 0;
}
