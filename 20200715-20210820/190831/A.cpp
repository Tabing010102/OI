#include <cstdio>
#include <cstring>

const int maxn = 5000000+10;

bool first;
int T, cnt, ops;
long long ans;
long long d[maxn], qd[maxn];

int max(int a, int b) { return a<b?b:a; }

/*void PUSH(int v) {
	cnt++;
	qd[cnt] = max(qd[cnt-1], v);
	if(first) { ans = qd[cnt]; first = false; }
	else ans ^= (qd[cnt]*ops);
}

void POP() {
	if(cnt == 0) {
		if(first) { ans = 0; first = false; }
		else ans ^= 0;
	} else {
		cnt--;
		ans ^= (qd[cnt]*ops);
	}
}*/

void PUSH(long long v) {
	cnt++;
	qd[cnt] = max(qd[cnt-1], v);
	if(cnt) ans ^= (qd[cnt]*ops);
}

void POP() {
	if(cnt == 0) {
		
	} else {
		cnt--;
		if(cnt) ans ^= (qd[cnt]*ops);
	}
}

int n, p, q, m;
unsigned int SA, SB, SC;
unsigned int rng61(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
void gen() {
	scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
	for(int i = 1; i <= n; i++) {
		ops++;
		if(rng61() % (p+q) < p) {
			long long x = rng61() % m + 1;
			//printf("fff:%d\n", x);
			PUSH(x);
		} else
			POP();
	}
}

int main() {
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		memset(d, 0, sizeof(d));
		memset(qd, 0, sizeof(qd));
		ans = cnt = ops = 0;
		first = true;
		gen();
		printf("Case #%d: %I64d\n", i, ans);
	}
	/*for(int i = 1; i <= T; i++) {
		memset(d, 0, sizeof(d));
		memset(qd, 0, sizeof(qd));
		ans = cnt = ops = 0;
		first = true;
		ops++; POP(); ops++; POP(); ops++;
		PUSH(1); ops++; PUSH(4); ops++;
		printf("%d\n", ans);
	}*/
	return 0;
}

