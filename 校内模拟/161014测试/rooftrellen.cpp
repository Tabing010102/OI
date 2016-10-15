#include <cstdio>
using namespace std;
FILE *fin, *fout;
int T, n, m, id;
int main() {
	fin = fopen("rooftrellen.in", "r");
	fout = fopen("rooftrellen.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &id);
	fscanf(fin, "%d", &T);
	while(T--) {
		fscanf(fin, "%d%d", &n, &m);
		int _max=0, tmp, cost=0;
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			fscanf(fin, "%d" ,&tmp);
//			fprintf(fout, "n=%d, m=%d, _max=%d, cost=%d\n", n, m, _max, cost);
			if(cost > m) {
				flag = false;
				int ttt;
				for(int k = i+1; k <= n; k++) fscanf(fin, "%d", &ttt);
				break;
			}
//			fprintf(fout, "Before tmp=%d, cost=%d, _max=%d\n", tmp, cost, _max);
			if(tmp <= _max) {
				cost += _max-tmp;
			} else {
				cost += (i-1)*(tmp-_max);
				_max = tmp;
			}
//			fprintf(fout, "After tmp=%d, cost=%d, _max=%d\n", tmp, cost, _max);
		}
		if(!flag) fprintf(fout, "No\n");
		else {
			if((m-cost)%n == 0) fprintf(fout, "Yes\n");
			else fprintf(fout, "No\n");
		}
	}
	return 0;
}
