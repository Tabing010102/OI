#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=10000+100;
const int INF=999999999;
struct Edge{
	int from,to,dist;
};
vector<int> G[maxn];
vector<Edge> edges;
queue<int> q;
int N,M,A,K,d[maxn];
bool inq[maxn];
void AddEdge(int A,int B,int C){
	edges.push_back((Edge){A,B,C});
	G[A].push_back(edges.size()-1);
}
void SPFA(int s){
	memset(inq,0,sizeof(inq));
	d[s]=0;
	q.push(s);
	inq[s]=true;
	while(!q.empty()){
		int u=q.front(); q.pop();
		inq[u]=false;
		for(int i=0;i<G[u].size();i++){
			Edge &e=edges[G[u][i]];
			if(d[e.to]>d[u]+e.dist){
				d[e.to]=d[u]+e.dist;
				q.push(e.to);
				inq[e.to]=true;
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&N,&M,&A,&K);
	for(int i=1;i<=M;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		AddEdge(a,b,c);
		AddEdge(b,a,c);
	}
	for(int i=1;i<=N;i++) d[i]=INF;
	for(int i=1;i<=A;i++){
		int t; scanf("%d",&t);
		SPFA(t);
		int ans=0;
		for(int j=1;j<=N;j++)
			if(j!=t&&d[j]>=K)
			    ans++;
		printf("%d\n",ans);
	}
//	system("pause");
	return 0;
}
