#include<iostream>
#include<cstdio>
#include<deque>
#include<cstdlib>
using namespace std;
int m,n,ans;
deque<int> q;
bool find(int x){
	for(deque<int>::iterator it=q.begin();it!=q.end();it++)
	if(*it==x) return true;
	return false;
}
int main(){
	freopen("translate.in","r",stdin);
	freopen("translate.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int t; cin>>t;
		if(!find(t))
		    if(q.size()==m){q.pop_back();q.push_front(t);ans++;}
		    else{q.push_front(t);ans++;}
	}
	cout<<ans;
	//system("pause");
	return 0;
}
