#include<cstdio>//造人;i,i+N表一个人
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=20000+10;
const int maxm=100000+10;
struct pr{
	int x,y,v;
}d[maxm];
int fa[2*maxn],N,M,ans;
bool cmp(const pr &a,const pr &b){return a.v>b.v;}
int find(int x){return x==fa[x]?x:find(fa[x]);}
int main(){
	freopen("prison1.in","r",stdin);
	freopen("prison1.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
		scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].v);
	sort(d,d+M,cmp);
	for(int i=1;i<=2*N;i++) fa[i]=i;
	for(int i=0;i<M;i++){
		int fx=find(d[i].x),fy=find(d[i].y);
		if(fx==fy){ans=d[i].v; break;}
		else{
			fa[fx]=find(d[i].y+N);
			fa[fy]=find(d[i].x+N);
		}
	}
	printf("%d",ans);
	return 0;
}
