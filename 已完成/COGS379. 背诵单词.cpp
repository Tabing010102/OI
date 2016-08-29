#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
string s[105];
int main(){
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n);
	for(int i=0;i<n;i++) cout<<s[i]<<endl;
    return 0;
}
