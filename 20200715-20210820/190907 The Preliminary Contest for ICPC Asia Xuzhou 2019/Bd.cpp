#include <cstdio>
#include <cstdlib>
#include <ctime>

FILE *fout;

int main() {
	srand(time(NULL));
	fout = fopen("bd.txt", "w");
	fprintf(fout, "1000000000 1000000\n");
	for(int i = 0; i < 1000000; i++) fprintf(fout, "%d %d\n", rand()%2+1, rand()%1000000000);
	return 0;
}
