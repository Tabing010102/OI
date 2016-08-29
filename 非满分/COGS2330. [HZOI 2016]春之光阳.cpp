#include<fstream>
#include<algorithm>
using namespace std;
const int maxn=5000+10;
struct data{
	int id,v;
	data(){id=v=0;}
}a[maxn];
int n,b[maxn];
bool cmp(const data &a,const data &b){
	return a.v<b.v;
}
fstream fin,fout;
int main(){
	fin.open("gnirps.in",ios::in);
	fout.open("gnirps.out",ios::out);
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) b[a[i].id]=i;
	for(int i=1;i<=10;i++){
		if(!prev_permutation(b+1,b+1+n)) break;
		fout<<"total "<<i<<":";
		for(int j=1;j<=n;j++) fout<<" "<<b[j];
		if(i<10) fout<<endl<<endl;
		else fout<<endl;
	}
	fin.close(); fout.close();
	return 0;
}
