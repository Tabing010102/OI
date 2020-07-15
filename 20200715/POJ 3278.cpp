#include <cstdio>
#include <cstdlib>

const int INF = 0x7fffffff;

int N, K, mins=0, maxs=0, _limit;
bool _ok;

inline int abs(int a) { return a<0?-a:a; }
inline int min(int a, int b) { return a<b?a:b; }

void get_min_max() {
	int cnt=N, cnts=0;
	while(cnt < K) { cnt <<= 1; cnts++; }
	printf("cnt=%d, cnts=%d\n", cnt, cnts);
	mins = cnts;
	maxs = cnts + min(abs(cnt-K), abs(K-cnt/2));
	printf("mins=%d maxs=%d\n", mins, maxs);
}

int get(int cnt, int times) {
	for(int i = 0; i < times; i++) {
		if(cnt > cnt*2) return INF;
		cnt *= 2;
	}
	return cnt;
}

void dfs(int dep, int cnt) {
	if(_ok) return;
	printf("dfs #%d : %d\n", dep, cnt);
	if(cnt == K) { _ok = true; return; }
	if(dep >= _limit) return;
	if(get(cnt, (_limit-dep)) < K) return;
	if(get(cnt, (_limit-dep)) == K) { _ok = true; return; }
	if(get(cnt, (_limit-dep))>K && get(cnt, (_limit-dep-1))<K &&
		(abs(get(cnt, (_limit-dep))-K)>_limit-dep || abs(get(cnt, (_limit-dep-1))-K)>_limit-dep)) return;
	dfs(dep+1, cnt-1);
	dfs(dep+1, cnt+1);
	dfs(dep+1, cnt<<1);
}

int bsearch() {
	int L=mins, R=maxs;
	while(L < R) {
		int M = L+(R-L)/2;
		_limit = M;
		_ok = false;
		dfs(0, N);
		if(_ok) R = M;
		else L = M+1;
		printf("L=%d R=%d\n", L, R);
	}
	return L;
}

int main() {
	scanf("%d%d", &N, &K);
	if(N >= K) { printf("%d\n", N-K); exit(0); }
	get_min_max();
	if(mins == maxs) { printf("%d\n", mins); exit(0); }
	printf("%d\n", bsearch());
	return 0;
}
