#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef long long LL;
const LL maxn=200100;
LL n,m,S,mw;
LL w[maxn],v[maxn],l[maxn],r[maxn],sum[maxn],cnt[maxn];//sum前缀和,cnt个数 
LL solve(LL W){
	for(LL i=1;i<=n;i++){
		sum[i]=sum[i-1]; cnt[i]=cnt[i-1];
		if(w[i]>=W){sum[i]+=v[i]; cnt[i]++;}
	}
	LL ans=0;
	for(LL i=1;i<=m;i++) ans+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("qc.in","r",stdin);
	freopen("qc.out","w",stdout);
	cin>>n>>m>>S;
	for(LL i=1;i<=n;i++){
		cin>>w[i]>>v[i]; mw=max(mw,w[i]);
	}
	for(LL i=1;i<=m;i++) cin>>l[i]>>r[i];
	LL l=0,r=mw+1,mid;
	while(l<r-1){
		mid=l+(r-l)/2;
		if(solve(mid)>S) l=mid;
		else r=mid;
	}
	cout<<min(abs(solve(l)-S),abs(solve(r)-S));
	return 0;
}
