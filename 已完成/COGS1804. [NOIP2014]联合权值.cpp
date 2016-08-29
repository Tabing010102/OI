#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=200010;
const int MOD=10007;
vector<int> G[maxn];
vector<int>::iterator it;
int n,w[maxn],maxv,total;
inline int sqr(int x){
	return x*x;
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
}
void work(int now){
	int max1=-1,max2=-1;//max1=G[now]相邻的两边中第一大的权值max2第二大
	int sum=0;//sum与G[now]相邻的所有权值的和
	for(it=G[now].begin();it!=G[now].end();it++){
		sum+=w[*it]; sum%=MOD;//加
		if(w[*it]>max2)
			if(w[*it]>max1){//w[*it]比两个都大 
				max2=max1;
				max1=w[*it];
			}else max2=w[*it];//w[*it]只比max2大 
	}
	for(it=G[now].begin();it!=G[now].end();it++){
		total+=sum*w[*it]-sqr(w[*it]); total%=MOD;//排除w[*it]本身
		maxv=max(maxv,max1*max2); 
	}
}
int main(){
	freopen("linkb.in","r",stdin);
	freopen("linkb.out","w",stdout);
	init();
	for(int i=1;i<=n;i++) work(i);
	printf("%d %d",maxv,total);
	return 0;
}
