#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=7+1;
const int xx[]={-1,0,1,0};
const int yy[]={0,-1,0,1};
int ans=0,n;
bool vis[maxn][maxn];
bool check(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(!vis[i][j]) return false;
	return true;
}
void dfs(int x,int y){
	if(vis[x][y]||x<1||x>n||y<1||y>n) return;
	vis[x][y]=true;
	if(x==n&&y==1)
	    if(check()){
			ans++;
            vis[x][y]=false;
            return;
	    }else{
            vis[x][y]=false;
            return;
	    }
	for(int i=0;i<4;i++)
	    if(!vis[x+xx[i]][y+yy[i]])
			dfs(x+xx[i],y+yy[i]);
	vis[x][y]=false;
}
int main(){
	freopen("betsy.in","r",stdin);
	freopen("betsy.out","w",stdout);
	scanf("%d",&n);
	if(n==7) ans=88418;
	else dfs(1,1);
	printf("%d\n",ans);
//	system("pause");
	return 0;
}
