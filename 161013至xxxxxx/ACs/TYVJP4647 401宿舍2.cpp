#include <cstdio>
using namespace std;
int m, n, t;
int main() {
	scanf("%d%d%d", &m, &n, &t);
	if(n * (t + t) >= m) printf("T");
	else printf("H");
	return 0;
}
