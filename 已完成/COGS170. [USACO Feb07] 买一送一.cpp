#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int high[maxn],low[maxn],n,m,ans;
int main(){
	freopen("buyfree.in","r",stdin);
	freopen("buyfree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&high[i]);
	for(int i=0;i<m;i++) scanf("%d",&low[i]);
	sort(high,high+n);
	sort(low,low+m);
	int a=n-1,b=m-1;
	while(1){
		if(a<0||b<0) break;
		while(b>=0&&high[a]<=low[b]) b--;
		if(a<0||b<0) break;
		ans++; a--,b--;
	}
	ans+=n;
	printf("%d",ans);
//	system("pause");
	return 0;
}
