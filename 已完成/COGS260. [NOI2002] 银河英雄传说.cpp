#include<cstdio>
using namespace std;
int fa[30001],count[30001],before[30001],t;
inline int abs(int a){return a<0?-a:a;}
int find(int x){
	if(fa[x]==x) return x;
	else{
		int fx=find(fa[x]);
		before[x]+=before[fa[x]];
		return fa[x]=fx;
	}
}
void uunion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	before[fx]=count[fy];
	count[fy]+=count[fx];
}
int ask(int x,int y){
	if(find(x)==find(y)) return abs(before[x]-before[y])-1;
	else return -1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=30000;i++) fa[i]=i,before[i]=0,count[i]=1;
	for(int i=1;i<=t;i++){
		char buf[10]; scanf("%s",buf);
		int l,r; scanf("%d%d",&l,&r);
		if(buf[0]=='M') uunion(l,r);
		else printf("%d\n",ask(l,r));
	}
	return 0;
}
