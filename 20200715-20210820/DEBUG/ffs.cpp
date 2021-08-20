#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500000+10;

int n, lft, ans=0;
int w[maxn], v[maxn], r[maxn];

bool cmp(const int a, const int b) { return (double)v[a]/w[a] > (double)v[b]/w[b]; }

int main() {
	scanf("%d%d", &n, &lft); lft--;
	for(int i = 0; i < n; i++) scanf("%d%d", &w[i], &v[i]);
	for(int i = 0; i < n; i++) r[i] = i;
	sort(r, r+n, cmp);
	for(int i = 0; i < n; i++) {
		if(lft < w[r[i]]) continue;
		if(lft <= 0) break;
		lft -= w[r[i]];
		ans += v[r[i]];
	}
	printf("%d\n", ans);
	return 0;
}
