#include <cstdio>
using namespace std;
FILE *fin, *fout;
int n; 
int main() {
	fin = fopen("bplusa.in", "r");
	fout = fopen("bplusa.out", "w");
	fscanf(fin, "%d", &n);
	fprintf(fout, "0 %d", n);
	return 0;
}
