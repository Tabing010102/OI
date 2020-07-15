#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod =1e9+7;

LL qpow(int n){
	LL ans=1,a=2;
	while(n){
		if (n&1) ans=ans*a%mod;
		a=a*a%mod; n/=2;
	}
	return ans;
}



int main (){
	LL n;
	cin >> n;
	cout << qpow(n) <<endl;	
	return 0;
}
