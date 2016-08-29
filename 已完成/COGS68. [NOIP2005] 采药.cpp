#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105;
int T,M,t[maxn],c[maxn],f[100005];
FILE *fin,*fout;
int main(){
	fin=fopen("medic.in","r");
	fout=fopen("medic.out","w");
	fscanf(fin,"%d%d",&T,&M);
	for(int i=1;i<=M;i++) fscanf(fin,"%d%d",&t[i],&c[i]);
	for(int i=1;i<=M;i++) for(int j=T;j>=0;j--)
		if(j-t[i]>=0) f[j]=max(f[j],f[j-t[i]]+c[i]);
		else f[j]=f[j];
	fprintf(fout,"%d",f[T]);
	return 0;
}
