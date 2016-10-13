#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int> >dd;
int n,m;
FILE *fin,*fout;
int main(){
	fin=fopen("2333_.in","r");
	fout=fopen("2333_.out","w");
//	fin=stdin; fout=stdout;
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		fscanf(fin,"%d",&t);
		if(!dd.count(t)) dd.insert(map<int,vector<int> >::value_type(t,vector<int>()));
		dd[t].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int k,v;
		fscanf(fin,"%d%d",&k,&v);
		if(!dd.count(v)) fprintf(fout,"0\n");
		else if(k>dd[v].size()) fprintf(fout,"0\n");
		else fprintf(fout,"%d\n",dd[v][k-1]);
	}
	return 0;
} 
