#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,k,x;
int PowerMod(int a,int b,int c){//a^b%c
	int ans=1; a=a%c;
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
	freopen("CircleNOIP2013.in","r",stdin);
	freopen("CircleNOIP2013.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d",(x+m*PowerMod(10,k,n))%n);
	//system("pause");
	return 0;
}
