#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2000000+10;
int n,d[maxn];
FILE *fin,*fout;
int main(){
	fin=fopen("sorttest.in","r");
	fout=fopen("sorttest.out","w");
//	fout=stdout;
	fscanf(fin,"%d",&n);
	for(int i=0;i<n;i++) fscanf(fin,"%d",&d[i]);
	sort(d,d+n);
	for(int i=0;i<n;i++) fprintf(fout,"%d ",d[i]);
	return 0;
}
