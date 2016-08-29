#include<iostream>
#include<cstdlib>
#include<bitset>
using namespace std;
const int maxn=100000+10;
bitset<30> pat[maxn];
bitset<30> t;
int n,m,ans,tt;
int main(){
	//ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>tt; pat[i]=tt;
	}
	for(int i=1;i<=m;i++){
		cin>>tt; t=tt;
		for(int i=1;i<=n;i++){
			int tot=0;
			for(int j=0;j<30&&tot<=2;j++) if(pat[i][j]!=t[j]) tot++;
			if(tot==2) ans++;
		}
	}
	cout<<ans;
	system("pause");
	return 0;
}
