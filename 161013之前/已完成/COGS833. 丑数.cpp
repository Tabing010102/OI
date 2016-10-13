#include<cstdio>//这。。。。
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=2147483647;
struct data{
	int fa,v;//fa初始下标
	bool operator<(const data &a)const{
		return v>a.v;
	}
	bool operator==(const data &a)const{
		return fa==a.fa&&v==a.v;
	}
	data operator=(const data &a){
		fa=a.fa; v=a.v;
	}
};
priority_queue<data> pq;
int d[100+10],K,N;
int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	cin>>K>>N;
	for(int i=0;i<K;i++){
		cin>>d[i];
		pq.push((data){i,d[i]});
	}
	data last={-1,-1};
	for(int i=1;i<N;i++){
		while(pq.top()==last) pq.pop();
		data x=pq.top(); pq.pop(); last=x;
		for(int j=x.fa;j<K;j++)
		    if((LL)x.v*(LL)d[j]<INF)
				pq.push((data){j,x.v*d[j]});
	}
	cout<<pq.top().v;
//	system("pause");
	return 0;
}
