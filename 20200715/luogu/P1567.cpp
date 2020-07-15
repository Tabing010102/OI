#include <cstdio>

int N, last=-1, cnt=0, ans=0;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		int t; scanf("%d", &t);
		if(t > last) last=t, cnt++;
		else last=t, ans=(cnt>ans)?cnt:ans, cnt=1;
	}
	printf("%d\n", ans);
	return 0;
}
