#include <cstdio>
#include <cstring>
#include <cmath>

bool p[50] = { 0 };
bool used[21] = { 0 };
int cnt[21] = { 0 };
int ans = 0;

void print() {
	printf("<%d>: ", ans++);
	for(int i = 0; i < 20; i++) printf("%d ", cnt[i]);
	printf("\n");
}

void dfs(int dep) {
	if(dep == 20) {
		if(p[cnt[19]+cnt[0]] == 0) print();
		return;
	}
	for(int i = 1; i <= 20; i++) if(!used[i]) {
		if(dep == 0) {
			cnt[dep] = i;
			used[i] = 1;
			dfs(dep+1);
			used[i] = 0;
		} else if(p[i+cnt[dep-1]] == 0) {
			if(i+cnt[dep-1] == 9) printf("fff\n");
			cnt[dep] = i;
			used[i] = 1;
			dfs(dep+1);
			used[i] = 0;
		}
	}
}

void get_prime() {
	int m = sqrt(40+0.5);
	for(int i = 2; i <= m; i++) if(!p[i]) for(int j = i*i; j <= 40; j += i) p[j] = 1;
}

int main() {
	get_prime();
	memset(p, 0, sizeof(p));
	memset(used, 0, sizeof(used));
	memset(cnt, 0, sizeof(cnt));
	dfs(0);
	return 0;
}
