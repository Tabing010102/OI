#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct Edge{
	int from,to;
};
const int maxn=65534+10;
vector<Edge> edges;
vector<int> G[maxn];
vector<int>::iterator it;
int n,in[maxn],tmp[maxn];
queue<int> q;
void AddEdge(int A,int B){
	edges.push_back((Edge){A,B});
	G[A].push_back(edges.size()-1);
}
int solve(int s){
	memcpy(tmp,in,sizeof(in));
	//for(int i=1;i<=n;i++) tmp[i]=in[i];
	tmp[s]=0; q.push(s);
	int ans=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(it=G[x].begin();it!=G[x].end();it++){
			int xx=edges[*it].to;
			tmp[xx]--;
			if(tmp[xx]<=0){
                q.push(xx);
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int t;
		while(scanf("%d",&t)){
			if(t==0) break;
			AddEdge(t,i);
			in[i]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d\n",solve(i));
	//system("pause");
	return 0;
}
