#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=100000+5;
int n,m,tot,d[maxn],ans;
bool vis[maxn];
vector<int> G[maxn];
vector<int>::iterator it;
queue<int> q;
int main(){
	freopen("asm_game.in","r",stdin);
	freopen("asm_game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
		d[u]++; d[v]++;
	}
	/*
	do{
		tot=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&d[i]<3){
                for(it=G[i].begin();it!=G[i].end();it++) d[*it]--;
                G[i].clear(); vis[i]=true;
			}
	}while(tot!=0);
	*/
	for(int i=1;i<=n;i++) if(d[i]<3){q.push(i); vis[i]=true;}
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(it=G[x].begin();it!=G[x].end();it++){
			d[*it]--;
			if(!vis[*it]&&d[*it]<3){q.push(*it); vis[*it]=true;}
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans^=i;
	printf("%d",ans);
	return 0;
}
