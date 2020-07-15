#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 1e4+10;

int n, k=1, d[maxn], r[maxn];

bool cmp(const int &a, const int &b) { return d[a] < d[b]; }

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &d[i]);
	for(int i = 0; i < n; i++) r[i] = i;
	sort(r, r+n, cmp);
	//for(int i = 0; i < n; i++) printf("%d ", r[i]); printf("\n");
	for(int i = 0; i < k; i++) { int tmp = d[r[i]]; d[r[i]] = d[r[n-i-1]]; d[r[n-i-1]] = tmp; }
	for(int i = 0; i < n; i++) printf("%d ", d[i]);
	return 0;
}
