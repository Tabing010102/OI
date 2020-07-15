#include <cstdio>

const int d[5][5] = { { 0, -1, 1, 1, -1 },
					  { 1, 0, -1, 1, -1 },
					  { -1, 1, 0, -1, 1 },
					  { -1, -1, 1, 0, 1 },
					  { 1, 1, -1, -1, 0 } };
const int maxn = 200+10;
int N, NA, NB, ansA=0, ansB=0;
int dA[maxn], dB[maxn];

int main() {
	scanf("%d%d%d", &N, &NA, &NB);
	for(int i = 0; i < NA; i++) scanf("%d", &dA[i]);
	for(int i = 0; i < NB; i++) scanf("%d", &dB[i]);
	for(int i = 0; i < N; i++)
		if(d[dA[i%NA]][dB[i%NB]] > 0) ansA++;
		else if(d[dA[i%NA]][dB[i%NB]] < 0) ansB++;;
	printf("%d %d\n", ansA, ansB);
	return 0;
}
