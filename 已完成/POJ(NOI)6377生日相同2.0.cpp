#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct st{
	int id;
	string name;
}d[181];
int n,isout;
bool cmp(const st& a,const st& b){
	if(a.id==b.id)
	    if(a.name.size()==b.name.size()) return a.name<b.name;
	    else return a.name.size()<b.name.size();
	else return a.id<b.id;
}
void print(int beg,int end){
	cout<<d[beg].id/100<<' '<<d[beg].id%100;
	for(int i=beg;i<=end;i++) cout<<' '<<d[i].name;
	cout<<endl;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d[i].name;
		int month,day; cin>>month>>day;
		d[i].id=month*100+day;
	}
	sort(d,d+n,cmp);
	int now=0;
	while(now<n){
		if(d[now].id!=d[now+1].id) now++;
		else{
			isout=true; int t=now;
			while(d[t+1].id==d[now].id) t++;
			print(now,t); now=t+1;
		}
	}
	if(!isout) cout<<"None";
	system("pause");
	return 0;
}
