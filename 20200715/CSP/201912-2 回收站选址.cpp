#include <cstdio>
#include <map>

using std::map;

int ans[5], n;
map<int, map<int, int> > m;
map<int, map<int, int> >::iterator it1;
map<int, int>::iterator it2;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		m[x][y] = 1;
	}
	for(it1 = m.begin(); it1 != m.end(); it1++) {
		for(it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
			if(it2->second != 1) continue;
			if(m[it1->first][it2->first-1] && m[it1->first][it2->first+1] && m[it1->first-1][it2->first] && m[it1->first+1][it2->first]) {
				int cnt = 0;
				if(m[it1->first-1][it2->first-1]) cnt++;
				if(m[it1->first-1][it2->first+1]) cnt++;
				if(m[it1->first+1][it2->first-1]) cnt++;
				if(m[it1->first+1][it2->first+1]) cnt++;
				ans[cnt]++;
			}
		}
	}
	for(int i = 0; i < 5; i++) printf("%d\n", ans[i]);
	return 0;
}
