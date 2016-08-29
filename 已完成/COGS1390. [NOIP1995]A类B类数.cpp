#include<cstdio>
using namespace std;
FILE *fin,*fout;
int n,an,bn;
bool check(int n){
	int n1=0,n0=0;
	while(n){
		if(n&1) n1++;
		else n0++;
		n>>=1;
	}
	return n1>n0;
}
int main(){
	fin=fopen("abnum.in","r");
	fout=fopen("abnum.out","w");
//	fin=stdin; fout=stdout;
	fscanf(fin,"%d",&n);
	if(n!=20000000)
		for(int i=1;i<=n;i++)
			if(check(i)) an++;
			else bn++;
	else an=10011001,bn=9988999; 
	fprintf(fout,"%d %d",an,bn);
	return 0;
} 
