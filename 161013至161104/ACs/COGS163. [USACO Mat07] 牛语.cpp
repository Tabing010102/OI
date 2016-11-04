#include <cstdio>
#include <cstring>
using namespace std;
int n;
char buf[50];
FILE *fin, *fout;
bool check(char c) {
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}
int main() {
	fin = fopen("latin.in", "r");
	fout = fopen("latin.out", "w");
//	fout = stdout;
	fscanf(fin, "%d", &n);
	for(int i = 1; i <= n; i++) {
		fscanf(fin, "%s", buf);
		if(check(buf[0])) {
			fprintf(fout, "%s", buf);
			fprintf(fout, "cow\n");
		} else {
			int len = strlen(buf);
			for(int j = 1; j < len; j++)
				fprintf(fout, "%c", buf[j]);
			fprintf(fout, "%c", buf[0]);
			fprintf(fout, "ow\n");
		}
	}
	return 0;
}
