/*
状态定义：f[i]为切掉i时最大价值
状态转移：f[i]=f[i-k]+d[k]切掉长度为k的
边界：f[0]=0;
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2000+10;
int n,d[maxn],f[maxn],last[maxn];
vector<int> ans;
vector<int>::iterator it;
int dp(int x){
	if(x==0) return 0;
	if(f[x]) return f[x];
	int maxf=-1,maxc=-1;
	for(int i=x;i>=1;i--)
		if(dp(x-i)+d[i]>maxf){
			maxf=dp(x-i)+d[i];
			maxc=i;
		}
	last[x]=maxc;
	return f[x]=maxf;
}
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("cutrod.in","r",stdin);
	freopen("cutrod.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	printf("%d\n",dp(n));
//	for(int i=1;i<=n;i++) printf("%d ",last[i]);
//	putchar('\n');
	int p=n;
	while(p){
		ans.push_back(last[p]);
		p-=last[p];
	}
	sort(ans.begin(),ans.end(),cmp);
	for(it=ans.begin();it!=ans.end();it++) printf("%d ",*it);
//	system("pause");
	return 0;
}
