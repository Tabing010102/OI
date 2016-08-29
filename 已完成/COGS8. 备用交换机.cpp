#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,nn[110],tot,cur[110];
vector<int> G[110];
vector<int> ans;
bool vis[110];
void dfs(int u){
	for(int i=0;i<nn[u];i++)
	    if(!vis[G[u][i]]){
			vis[G[u][i]]=true;
			dfs(G[u][i]);
		}
}
int main(){
	freopen("gd.in","r",stdin);
	freopen("gd.out","w",stdout);
	scanf("%d",&n);
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		G[a].push_back(b); nn[a]++;
		G[b].push_back(a); nn[b]++;
	}
	for(int i=1;i<=n;i++){
		if(!nn[i]) continue;
		memset(vis,0,sizeof(vis));
		vis[G[i][0]]=true;//���Ծ���i�ڵ㣬G[u][i]�ɵ���Ľڵ���(n1)
		dfs(G[i][0]);
		int n1=0;
		for(int i=1;i<=n;i++)
		    if(vis[i])
		        n1++;
		memset(vis,0,sizeof(vis));
		vis[i]=true;//���ɾ���i�ڵ㣨�������𻵣���G[u][i]�ɵ���Ľڵ���(n2)
		vis[G[i][0]]=true;
		dfs(G[i][0]);
		int n2=0;
        for(int i=1;i<=n;i++)
		    if(vis[i])
		        n2++;
		if(n1!=n2){//�����һ����˵��ȥ��i(i�Ľ�������)����������ڵ�ͨѶ�ж�
			tot++;
			ans.push_back(i);
		}
	}
	printf("%d\n",tot);
	if(tot)
	    for(int i=0;i<tot;i++)
	        printf("%d\n",ans[i]);
	//system("pause");
	return 0;
}
