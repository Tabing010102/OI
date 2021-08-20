#include <cstdio>

const int maxn = 1000+10;

int N, M, cnt=0, ans=0;
int q[maxn], qs=0, qe=0;

bool find(int x) {
	for(int i = qs; i < qe; i++)
		if(q[i] == x)
			return true;
	return false;
}

int main() {
	scanf("%d%d", &M, &N);
	for(int i = 0; i < N; i++) {
		int t; scanf("%d", &t);
		if(find(t)) continue;
		else {
			if(cnt >= M) { cnt--; qs++; }
			q[qe++] = t;
			cnt++;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
