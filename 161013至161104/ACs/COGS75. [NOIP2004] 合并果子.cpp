#include<cstdio>
#include<queue>
using namespace std;
int n, ans;
priority_queue<int, vector<int>, greater<int> > pq;
FILE *fin, *fout;
int main() {
	fin = fopen("fruit.in", "r");
	fout = fopen("fruit.out", "w");
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		int t; fscanf(fin, "%d", &t);
		pq.push(t);
	}
	while(pq.size() >= 2) {
		int t1 = pq.top(); pq.pop();
		int t2 = pq.top(); pq.pop();
		ans += t1 + t2;
		pq.push(t1+t2);
	}
	fprintf(fout, "%d", ans);
	return 0;
}
