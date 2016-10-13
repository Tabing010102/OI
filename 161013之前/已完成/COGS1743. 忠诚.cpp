#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int INF=999999999;
const int maxn=100000+10;
struct SEG{
	int l,r;
	int lch,rch;
	int min;
	void clear(){
		l=r=0;
		lch=rch=-1;
		min=INF;
	}
	void set(int x,int y){
		clear();
		l=x,r=y;
	}
}tree[2*maxn];
int tot=0;
int m,n;
int build(int x,int y){
	int p=tot++;
	SEG &now=tree[p];
	now.set(x,y);
	int mid=x+(y-x)/2;
	if(y>x){
		now.lch=build(x,mid);
		now.rch=build(mid+1,y);
	}
	return p;
}
void update_root(int root){
	SEG &now=tree[root];
	if(now.lch==-1) return;
	SEG &lson=tree[now.lch],&rson=tree[now.rch];
	now.min=min(lson.min,rson.min);
}
void update(int root,int point,int x){
	if(root==-1) return;
	SEG &now=tree[root];
	if(point<now.l||point>now.r) return;//error
	else if(point==now.l&&point==now.r) now.min=x;//error
	else{
		update(now.lch,point,x);
		update(now.rch,point,x);
		update_root(root);
	}
}
int query(int root,int x,int y){
	if(root==-1) return INF;
	int ans;
	SEG &now=tree[root];
	int lson=now.lch,rson=now.rch;
	if(y<now.l||x>now.r) return INF;//error
	else if(x<=now.l&&y>=now.r) return now.min;//error
	else{
		ans=query(lson,x,y);
		ans=min(ans,query(rson,x,y));
	}
	return ans;
}
int main(){
	freopen("faithful.in","r",stdin);
	freopen("faithful.out","w",stdout);
	scanf("%d%d",&m,&n);
	build(1,m);
	for(int i=1;i<=m;i++){
		int t; scanf("%d",&t);
		update(0,i,t);
	}
	int l,r; scanf("%d%d",&l,&r);
	printf("%d",query(0,l,r));
	for(int i=1;i<n;i++){
		scanf("%d%d",&l,&r);
		printf(" %d",query(0,l,r));
	}
//	system("pause");
	return 0;
}
