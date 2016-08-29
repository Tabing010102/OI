#include<cstdio>
#include<algorithm>
using namespace std;
int n,d[505],tot;
int main(){
	freopen("stats.in","r",stdin);
	freopen("stats.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		tot+=d[i];
	}
	sort(d+1,d+1+n);
	printf("%.6lf\n",(double)tot/n);
	if(n%2==0) printf("%.6lf",(double)(d[n/2]+d[n/2+1])/2);
	else printf("%.6lf",(double)d[n/2+1]);
	return 0;
} 
