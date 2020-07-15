#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 5000+10;

struct P {
	int id, s;
	P(int a=0, int b=0): id(a),s(b) {}
};

int n, m, tr, ts;
P d[maxn];

bool cmp(const P &a, const P &b) {
	if(a.s != b.s) return a.s > b.s;
	else return a.id < b.id;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int id, s;
		scanf("%d%d", &id, &s);
		d[i] = P(id, s);
	}
	sort(d, d+n, cmp);
	tr = (int)((double)m*1.5)-1;
	ts = d[tr].s;
	while(d[tr+1].s == ts) tr++;
	printf("%d %d\n", ts, tr+1);
	for(int i = 0; i <= tr; i++) printf("%d %d\n", d[i].id, d[i].s);
	return 0;
}
