#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n = 1000;
	printf("%d\n", n);
	for(int i = 0; i < n; i++) printf("%d\n", rand()%32767+2);
	return 0;
}
