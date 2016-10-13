#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,d[10010],maxx,len[10010];//last[10010];
string ss[10010];
bool judge(int a,int b){
	for(int i=0;i<len[b];i++)
	if(ss[b][i]!=ss[a][i]) return false;
	return true;
}
int main(){
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss[i]; len[i]=ss[i].size();
	}
	for(int i=0;i<n;i++) d[i]=1;//last[i]=i;
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--)
			if(len[i]>=len[j])
				if(d[j]+1>=d[i])
					if(judge(i,j)){
			//last[i]=j;
			d[i]=d[j]+1;
		}
	}
	for(int i=0;i<n;i++) if(d[i]>maxx) maxx=d[i];
	cout<<maxx;
	return 0;
}