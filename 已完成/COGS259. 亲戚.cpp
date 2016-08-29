#include<cstdio>
using namespace std;
const int maxn=20010;
int fa[maxn],n,m,q;
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
int main(){
	freopen("relations.in","r",stdin);
	freopen("relations.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int p1,p2; scanf("%d%d",&p1,&p2);
		int f1=find(p1),f2=find(p2);
		if(f1!=f2) fa[f1]=f2;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int t1,t2; scanf("%d%d",&t1,&t2);
		if(find(t1)==find(t2)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
