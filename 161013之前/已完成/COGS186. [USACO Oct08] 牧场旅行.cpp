#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;
const int maxn=1000+10;
const int INF=INT_MAX;
struct Edge{
	int from,to,dist;
};
struct HeapNode{
	int d,u;
	bool operator<(const HeapNode& rhs)const{
		return d>rhs.d;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int n,q,d[maxn];//p[maxn]
bool done[maxn];
void AddEdge(int A,int B,int C){
	edges.push_back((Edge){A,B,C});
	G[A].push_back(edges.size()-1);
}
void dijkstra(int s){
	priority_queue<HeapNode> q;
	for(int i=0;i<=n;i++) d[i]=INF;
	d[s]=0;
	memset(done,0,sizeof(done));
	q.push((HeapNode){0,s});
	while(!q.empty()){
		HeapNode x=q.top(); q.pop();
		int u=x.u;
		if(done[u]) continue;
		done[u]=true;
		for(int i=0;i<G[u].size();i++){
			Edge& e=edges[G[u][i]];
			if(d[e.to]>d[u]+e.dist){
				d[e.to]=d[u]+e.dist;
				//p[e.to]=G[u][i];
				q.push((HeapNode){d[e.to],e.to});
			}
		}
	}
}
int main(){
	freopen("pwalk.in","r",stdin);
	freopen("pwalk.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++){
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		AddEdge(A,B,C);
		AddEdge(B,A,C);
	}
	for(int i=0;i<q;i++){
		int A,B;
		scanf("%d%d",&A,&B);
		dijkstra(A); printf("%d\n",d[B]);
	}
	//system("pause");
	return 0;
}
