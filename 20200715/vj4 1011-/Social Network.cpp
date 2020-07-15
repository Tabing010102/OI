#include <cstdio>
#include <set>
#include <queue>

using namespace std;

const int maxn = 20000+10;

int n, k, ans[maxn];
set<int> s;
queue<int> q;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		if(s.count(t)) { continue; }
		else {
			if(q.size() < k) { s.insert(t); q.push(t); }
			else {
				int x = q.front(); q.pop();
				s.erase(x);
				q.push(t); s.insert(t);
			}
		}
	}
	int cnt = -1;
	while(!q.empty()) { ans[++cnt] = q.front(); q.pop(); }
	printf("%d\n", cnt+1);
	for(int i = cnt; i >= 0; i--) printf("%d ", ans[i]);
	return 0;
}
