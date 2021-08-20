#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	int times = 50000;
	printf("%d\n", times);
	for(int i = 0; i < times; i++) {
		int type = rand()%2+1;
		printf("%d ", type);
		int length = rand()%20+1;
		int havex = rand()%2;
		int xpos = rand()%length;
		for(int j = 0; j < length; j++) {
			if(type==2 && havex && j==xpos) putchar('*');
			else {
				int t = 'a'+(rand()%26);
				putchar(t);
			}
		}
		putchar('\n');
	}
}
