#include<fstream>
#include<string>
#include<map>
#include<cctype>
using namespace std;
int T,n;
string s;
map<string,int>ma;
map<string,int>::iterator it;
fstream fin,fout;
int main(){
	ios::sync_with_stdio(false);
	fin.open("nickname.in",ios::in);
	fout.open("nickname.out",ios::out);
	fin>>T;
	while(T--){
		ma.clear();
		fin>>n;
		for(int i=1;i<=n;i++){
			fin>>s;
			for(int j=0;j<s.size();j++) s[j]=tolower(s[j]);
			ma[s]++;
		}
		for(it=ma.begin();it!=ma.end();it++)
			fout<<it->first<<' '<<it->second<<endl;
	}
	return 0;
}
