/*
状态定义：f[i]为从1到i的最长上升子序列的长度
状态转移方程：f[i]=max(f[x]+1,f[x]); 1<=x<=i-1 d[i]>f[x];
边界：f[1..n]=1;
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int d[maxn],n,f[maxn],ans=-1;
FILE *fin,*fout;
int main(){
	fin=fopen("lis1.in","r");
	fout=fopen("lis1.out","w");
//	fout=stdout;
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)
		fscanf(fin,"%d",&d[i]);
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=1;i<=n;i++){
		int best=1;
		for(int j=1;j<i;j++)
			if(d[i]>d[j]) best=max(best,f[j]+1);
		f[i]=best;
		ans=max(ans,f[i]);
	}
	fprintf(fout,"%d\n",ans);
	return 0;
}