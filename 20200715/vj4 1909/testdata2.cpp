#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int times = 100000;
	printf("%d\n", times);
	for(int i = 0; i < times; i++) {
		int length = rand()%3+1;
		for(int j = 0; j < length; j++) {
				int t = 'a'+(rand()%26);
				int toup = rand()%2;
				if(toup) putchar(toupper(t));
				else putchar(t);
		}
		putchar('\n');
	}
}
