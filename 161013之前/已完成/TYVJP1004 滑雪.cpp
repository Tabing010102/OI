#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100+10;
const int xx[]={-1,1,0,0};
const int yy[]={0,0,-1,1};
int r,c,G[maxn][maxn],f[maxn][maxn];
int dp(int i,int j){
	if(i<1||i>r||j<1||j>c) return 0;
	if(f[i][j]) return f[i][j];
	int best=1;//最坏的情况：只有这个节点本身，长度为1
	for(int a=0;a<4;a++)
		if(G[i][j]>G[i+xx[a]][j+yy[a]])
			best=max(best,dp(i+xx[a],j+yy[a])+1);
	return f[i][j]=best;
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			scanf("%d",&G[i][j]);
	int best=-1;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			best=max(best,dp(i,j));
	printf("%d\n",best);
	return 0;
}