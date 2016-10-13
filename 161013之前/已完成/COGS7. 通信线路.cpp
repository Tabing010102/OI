#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int from,to,dist;
};
const int maxn=1501*1501;
int n,r[maxn],fa[1502],e_size;
vector<Edge> edges;
void AddEdge(int A,int B,int C){
    edges.push_back((Edge){A,B,C});
}
bool cmp(const int& a,const int& b){return edges[a].dist<edges[b].dist;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int Kruskal(){
    int ans=0;
    for(int i=0;i<n;i++) fa[i]=i;
    for(int i=0;i<e_size;i++) r[i]=i;
    sort(r,r+e_size,cmp);
    for(int i=0;i<e_size;i++){
        int e=r[i];
        int x=find(edges[e].from),y=find(edges[e].to);
        if(x!=y){ans+=edges[e].dist; fa[x]=y;}
    }
    return ans;
}
int main(){
    freopen("mcst.in","r",stdin);
    freopen("mcst.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int t; scanf("%d",&t);
        if(t!=-1) AddEdge(i,j,t);
    }
    e_size=edges.size();
    printf("%d",Kruskal());
    return 0;
}
