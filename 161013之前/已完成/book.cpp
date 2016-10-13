#include<cstdio>
using namespace std;
int a,b,c,d1[101],d2[101],d3[101];
long f[101][101][101];
inline long max1(long a,long b,long c){
	long t=a; if(t<b) t=b; if(t<c) t=c;
	return t;
}
long dp(int i,int j,int k,int step){
	if(i<0||j<0||k<0) return 0;
	if(f[i][j][k]) return f[i][j][k];
	return f[i][j][k]=max1(dp(i-1,j,k,step+1)+d1[i]*step,
		dp(i,j-1,k,step+1)+d2[j]*step,dp(i,j,k-1,step+1)+d3[k]*step);
}
int main(){
    freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&d1[i]);
	for(int i=1;i<=b;i++) scanf("%d",&d2[i]);
	for(int i=1;i<=c;i++) scanf("%d",&d3[i]);
	printf("%ld",dp(a,b,c,1));
	return 0;
}
