#include <cstdio>

void move(int cnt, char from, char tmp, char to) {
	if(cnt == 1) {
		printf("%c->%c\n", from, to);
		return;
	} else {
		move(cnt-1, from, to, tmp);
		move(1, from, tmp, to);
		move(cnt-1, tmp, from, to);
	}
}

int main() {
	int n; scanf("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}
