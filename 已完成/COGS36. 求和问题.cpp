#include<cstdio>
using namespace std;
long long n,A[10002],m,q1,q2,c,i;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&c);
		A[i]=c+A[i-1];
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&q1,&q2);
		printf("%lld\n",A[q2]-A[q1-1>0?q1-1:0]);
	}
	return 0;
}
