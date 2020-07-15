#include <cstdio>
#include <map>

using namespace std;

const int maxn = 1e6+10;

map<int, int> m;
int n;
int maxc=0, minn=0x7fffffff;

void ju(int count, int num) {
	if(count > maxc) { maxc = count; minn = num; }
	else if(count==maxc && num<minn) { minn = num; }
	else return;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int c = a xor b;
		m[a]++; ju(m[a], a);
		if(a != c) { m[c]++; ju(m[c], c); }
	}
	printf("%d", minn);
	return 0;
}
