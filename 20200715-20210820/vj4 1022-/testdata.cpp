#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int n = 10;
	printf("%d\n", n);
	for(int i = 0; i < n-1; i++) {
		int t = rand()*rand()%200000+1;
		printf("%d\n", t);
		for(int j = 0; j < t; j++) printf("%d", rand()%6+1);
		printf("\n");
		for(int j = 0; j < t; j++) printf("%d", rand()%6+1);
		printf("\n"); 
	}
	printf("200000\n");
	for(int i = 0; i < 39999; i++) printf("23232"); printf("22224"); printf("\n");
	for(int i = 0; i < 39999; i++) printf("16151"); printf("45326"); printf("\n");
	return 0;
}
