#include <iostream>

using namespace std;

const int maxn = 10+2;

typedef long long LL;

LL n, a[maxn], b[maxn], N;

void exgcd(LL a, LL b, LL &x, LL &y){
	LL t;
	if(b == 0) { x=1; y=0; return; }
	exgcd(b, a%b, x, y);
	t=x; x=y; y=t-(a/b)*y;
}

LL C(LL a[], LL m[], LL n) {
	LL M=1, ans=0, t, x, y;
	for(LL i = 0; i < n; i++) M *= m[i];
	for(LL i = 0; i < n; i++) {
		t = M/m[i];
		exgcd(t, m[i], x, y);
		ans = (ans+a[i]*x*t)%M;
	}
	return (ans+M)%M;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	N = C(b, a, n);
	//cout << N << endl;
	if(N<=1 || N>(LL)1e15) cout << "Tankernb!";
	else if(N%3 == 1) cout << "Zgxnb!";
	else cout << "Lbnb!";
	return 0;
}
