#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100000+10;

struct Edge{
	int from,to;
};

int n,m,d[maxn];//d[]原始数据
vector<Edge> edges; vector<Edge> opedges;//op-反图 
vector<int> G[maxn]; vector<int> opG[maxn];
bool can1[maxn],cann[maxn];//can1[]出发点可以到达的点;cann[]结束点可以到达的点 
//bool can[maxn];//可以去的点 

void AddEdge(int a,int b){
	edges.push_back((Edge){a,b});
	int m=edges.size();
	G[a].push_back(m-1);
}
void bfs(int s,bool vis[]){
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<G[u].size();i++)
		if(!vis[edges[G[u][i]].to]){
			q.push(edges[G[u][i]].to);
			vis[edges[G[u][i]].to]=true;
		}
	}
}
void opAddEdge(int a,int b){
	opedges.push_back((Edge){a,b});
	int m=opedges.size();
	opG[a].push_back(m-1);
}
void opbfs(int s,bool vis[]){
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<opG[u].size();i++)
		if(!vis[opedges[opG[u][i]].to]){
			q.push(opedges[opG[u][i]].to);
			vis[opedges[opG[u][i]].to]=true;
		}
	}
}


int main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=m;i++){
		int a,b,z;
		scanf("%d%d%d",&a,&b,&z);
		if(z==1){
			AddEdge(a,b);
			opAddEdge(b,a);
		}else{
			AddEdge(a,b); opAddEdge(b,a);
			AddEdge(b,a); opAddEdge(a,b);
		}
	}
	bfs(1,can1); opbfs(n,cann);
	can1[1]=0; cann[n]=0;//必须加上这两句 
//	for(int i=1;i<=n;i++) printf("%d:can1:%d cann:%d\n",i,can1[i],cann[i]);
	int minv=999,maxv=-1;
	for(int i=1;i<=n;i++) if(can1[i]&&cann[i]){
		minv=min(minv,d[i]);
		maxv=max(maxv,d[i]);
	}
	printf("%d",maxv-minv);
	return 0;
}
