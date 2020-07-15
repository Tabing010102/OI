#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 1000+10;

int M, N, K, L, D;
int dK[maxn], dL[maxn];
int rK[maxn], rL[maxn];

int min(int a, int b) { return a<b?a:b; }

bool cmpK(const int a, const int b) { return dK[a]>dK[b]; }
bool cmpL(const int a, const int b) { return dL[a]>dL[b]; }

int main() {
	scanf("%d%d%d%d%d", &M, &N, &K, &L, &D);
	for(int i = 0; i < D; i++) {
		int x, y, p, q;
		scanf("%d%d%d%d", &x, &y, &p, &q);
		if(x == p) dL[min(y, q)]++;
		else dK[min(x, p)]++;
	}
	for(int i = 1; i <= M; i++) rK[i] = i;
	for(int i = 1; i <= N; i++) rL[i] = i;
	sort(rK+1, rK+1+M, cmpK);
	sort(rL+1, rL+1+N, cmpL);
	sort(rK+1, rK+1+K);
	sort(rL+1, rL+1+L);
	bool first = true;
	for(int i = 1; i <= K; i++) {
		if(first) { printf("%d", rK[i]); first = false; }
		else printf(" %d", rK[i]);
	}
	printf("\n");
	first = true;
	for(int i = 1; i <= L; i++) {
		if(first) { printf("%d", rL[i]); first = false; }
		else printf(" %d", rL[i]);
	}
	return 0;
}
