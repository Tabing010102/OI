#include<cstdio>
#include<map>
#include<vector>
using namespace std;
struct Node{
	int d1,d2;
};
vector<Node> d;
vector<Node>::iterator it;
map<int,int> fa;
int tot,n;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool ask(){
	for(it=d.begin();it!=d.end();it++)
	if(find(it->d1)==find(it->d2)) return false;
	return true;
}
int main(){
	freopen("prog.in","r",stdin);
	freopen("prog.out","w",stdout);
	scanf("%d",&tot);
	while(tot--){
		scanf("%d",&n);
		fa.clear(); d.clear();
		for(int i=1;i<=n;i++){
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			if(!fa.count(t1)) fa[t1]=t1;
			if(!fa.count(t2)) fa[t2]=t2;
			if(t3==0) d.push_back((Node){t1,t2});
			else{
				int f1=find(t1),f2=find(t2);
				if(f1!=f2) fa[f1]=f2;
			}
		}
		if(ask()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
