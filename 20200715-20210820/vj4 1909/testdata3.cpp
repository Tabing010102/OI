#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n = 1000; int m = 1000;
	printf("%d %d\n", n, m);
	for(int i = 0; i < n; i++) {
		if(i == 2) for(int j = 0; j < m; j++) printf("0 ");
		else if(i == 4) for(int j = 0; j < m; j++) printf("0 ");
		else if(i == 6) for(int j = 0; j < m; j++) printf("0 ");
		else if(i == 8) for(int j = 0; j < m; j++) printf("0 ");
		else for(int j = 0; j < m; j++) printf("%d ", rand()%8>1); 
		printf("\n");
	}
}
