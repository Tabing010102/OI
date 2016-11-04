#include <fstream>
using namespace std;
typedef long long LL;
const LL maxn = 100000+10;
const LL MOD = 10007;
fstream fin, fout;
LL n, m, num[maxn], col[maxn], ans;
int main() {
	fin.open("2015sum.in", ios::in);
	fout.open("2015sum.out", ios::out);
	ios::sync_with_stdio(false);
	fin >> n >> m;
	for(LL i = 1; i <= n; i++) fin >> num[i];
	for(LL i = 1; i <= n; i++) fin >> col[i];
	for(LL i = 1; i <= n-2; i++) {
		for(LL j = i+1; j <= n-1; j++) {
			LL k = i+(j-i)*2;
			if(k > n) break;
			if(col[i] == col[k]) {
				ans += ((i%MOD + k%MOD)%MOD) * (num[i]%MOD + num[k]%MOD)%MOD;
				ans %= MOD;
			}
		}
	}
	fout << ans;
	return 0;
}
