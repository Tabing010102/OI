#include <cstdio>
#include <queue>
using namespace std;
FILE *fin, *fout;
deque<int> q;//queue没有迭代器，，，
int m, n, ans = 0;
int main() {
	fin = fopen("translate.in", "r");
	fout = fopen("translate.out", "w");
//	fout = stdout;
	fscanf(fin, "%d%d", &m, &n);
	for(int i = 1; i <= n; i++) {
		int t;
		fscanf(fin, "%d", &t);
		bool flag = false;
		for(deque<int>::iterator it = q.begin(); it != q.end(); it++)
			if(*it == t) { flag = true; break; }
		if(!flag) {
			ans++;
			if(q.size() == m) q.pop_front();
			q.push_back(t);
		}
	}
	fprintf(fout, "%d", ans);
	return 0;
}
