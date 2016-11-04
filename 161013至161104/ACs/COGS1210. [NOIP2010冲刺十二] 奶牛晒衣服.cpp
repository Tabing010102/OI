#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 500000+100;
FILE *fin, *fout;
int n, a, b;
priority_queue<int> pq;
int main() {
	fin = fopen("dry.in", "r");
	fout = fopen("dry.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n; i++) {
		int tmp;
		fscanf(fin, "%d", &tmp);
		pq.push(tmp);
	}
	int ans = 0;
	while(1) {
		int x = pq.top();
		pq.pop();
		if(x-ans*a <= 0) break;
		x -= b;
		pq.push(x);
		ans++;
	}
	fprintf(fout, "%d\n", ans);
	return 0;
}
