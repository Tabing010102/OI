#include <cstdio>
#include <cstring>
//#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int maxn = 500000+10;

struct haha {
	vector<int> s;
	bool operator == (const haha &rhs) const {
		if(s.size() != rhs.s.size()) return false;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != rhs.s[i]) return false;
		}
		return true;
	}
	bool operator < (const haha &rhs) const {
		if(s.size() != rhs.s.size()) return false;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != rhs.s[i]) return false;
		}
		return false;
	}
};

int T;
int d[maxn];
int n, l, ans;
//map<int, int> m;
set<haha > s;

void calc(int last, int cnt) {
	/*for(int i = l; i <= cnt-last; i++) ans += (cnt-last+1)-(i-1);
	if(d[last]!=d[cnt] && cnt-last+1>=l) ans++;*/
	for(int i = l; i <= cnt-last; i++) {
		haha tmp;
		for(int j = last; j <= cnt-(i-1); j++) tmp.s.push_back(d[j]);
		if(s.find(tmp) != s.end()) { s.insert(tmp); ans++; }
	}
	if(d[last]!=d[cnt] && cnt-last+1>=l) {
		haha tmp;
		for(int j = last; j <= cnt; j++) tmp.s.push_back(d[j]);
		if(s.find(tmp) != s.end()) { s.insert(tmp); ans++; }
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(d, 0, sizeof(d));
		ans = 0;
		s.clear();
		scanf("%d%d", &n, &l);
		if(l <= 2) l = 2;
		for(int i = 0; i < n; i++) scanf("%d", &d[i]);
		int cnt=0, last=0;
		//m.clear();
		while(1) {
			while(d[cnt]!=d[cnt+1] && cnt<n-1) cnt++;
			if(cnt >= n-1) { calc(last, n-1); break; }
			//else if(d[cnt] == d[cnt+1]) { calc(last, cnt); cnt++; last = cnt; }
			else { calc(last, cnt); cnt++; last = cnt; }
		}
		printf("%d\n", ans);
	}
	return 0;
}
