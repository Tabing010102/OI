#include <cstdio>
#include <map>

using namespace std;

map<int, int> m;
map<int, int> p;
int n, q, op, v;

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < q; i++) {
		scanf("%d%d", &op, &v);
		if(op == 1) {
			m[v] = 1;
			if(m[v+1]) p[v] = p[v+1];
			else p[v] = v+1>n?-1:v+1;
			if(p[v-1]) {
				int cnt = v-1;
				while(p[cnt]) { p[cnt]=p[v]; cnt--; }
			}
		}
		else {
			if(p[v]) printf("%d\n", p[v]);
			else {
				int cnt = v;
				while(m[cnt]) cnt++;
				if(cnt > n) printf("-1\n");
				else printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
