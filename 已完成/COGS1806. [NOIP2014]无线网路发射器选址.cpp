#include<cstdio>
using namespace std;
typedef long long LL;
int k[129][129],d,n;
LL slove(int i,int j){
	LL ans=0; int a,b,c,e;
	if(i-d<0) a=0; else a=i-d;
	if(i+d>128) b=128; else b=i+d;
	if(j-d<0) c=0; else c=j-d;
	if(j+d>128) e=128; else e=j+d;
	for(int m=a;m<=b;m++)
	for(int l=c;l<=e;l++)
	ans+=k[m][l];
	return ans;
}
int main(){
	freopen("wireless.in","r",stdin);
	freopen("wireless.out","w",stdout);
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		k[x][y]=t;
	}
	LL ans=0; int freq=0;
	for(int i=0;i<=128;i++) for(int j=0;j<=128;j++){
		LL t=slove(i,j);
		if(t>ans){ans=t; freq=1;}
		else if(t==ans) freq++;
	}
	printf("%d %lld",freq,ans);
	return 0;
}
