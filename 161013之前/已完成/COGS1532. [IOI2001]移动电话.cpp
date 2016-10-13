#include<cstdio>
using namespace std;
const int maxn=1024+10;
int d[maxn][maxn],s;
inline int lowbit(int x){return x&(-x);}
void add(int x,int y,int a){
	for(int i=x;i<=s;i+=lowbit(i))
	for(int j=y;j<=s;j+=lowbit(j))
	d[i][j]+=a;
}
int ask2(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	for(int j=y;j>0;j-=lowbit(j))
	sum+=d[i][j];
	return sum;
}
int ask(int l,int b,int r,int t){
	return ask2(r,t)-ask2(l,t)-ask2(r,b)+ask2(l,b);
}
int main(){
	freopen("mobilephones.in","r",stdin);
	freopen("mobilephones.out","w",stdout);
	while(1){
		int cmd; scanf("%d",&cmd);
		if(cmd==0) scanf("%d",&s);
		else if(cmd==1){
			int x,y,a; scanf("%d%d%d",&x,&y,&a);
			add(x+1,y+1,a);
		}else if(cmd==2){
			int l,b,r,t; scanf("%d%d%d%d",&l,&b,&r,&t);
			printf("%d\n",ask(l,b,r+1,t+1));
		}else if(cmd==3) break;
	}
	return 0;
}
