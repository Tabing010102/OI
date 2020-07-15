#include <cstdio>

int main() {
	int K; scanf("%d", &K);
	double cnt=1;
	int cntn=1;
	while(cnt <= K) {
		cntn++;
		cnt += 1.0/cntn;
	}
	printf("%d\n", cntn);
	return 0;
}
