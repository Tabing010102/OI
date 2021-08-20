#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n = rand()%175+6;
	printf("%d\n", n);
	for(int i = 0; i < n; i++) {
		int len = rand()%20+1;
		printf("%c", rand()%26+'A');
		for(int j = 1; j < len; j++) printf("%c", rand()%26+'a');
		printf(" %d %d\n", rand()%12+1, rand()%30+1);
	}
}
