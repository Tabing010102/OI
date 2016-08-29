#include<iostream>
#include<cstdlib>
#include<map>
#include<string>
#include<sstream>
using namespace std;
map<string,string> dict;
string s;
int main(){
	ios::sync_with_stdio(false);
	while(getline(cin,s),s!=""){
		stringstream ss(s);
		string s1,s2; ss>>s1>>s2;
		dict[s2]=s1;
	}
	while(cin>>s){
		if(dict.count(s)) cout<<dict[s]<<endl;
		else cout<<"eh"<<endl;
	}
	system("pause");
	return 0;
}
