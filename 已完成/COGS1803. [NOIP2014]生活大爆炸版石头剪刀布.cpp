#include<iostream>
#include<cstdio>
using namespace std;
const int sheet[5][5]={
{0,-1,1,1,-1},
{1,0,-1,1,-1},
{-1,1,0,-1,1},
{-1,-1,1,0,1},
{1,1,-1,-1,0}};
int ans1,ans2,d1[201],d2[202],n,zq1,zq2,t[201];
int main(){
	freopen("rps.in","r",stdin);
	freopen("rps.out","w",stdout);
	cin>>n>>zq1>>zq2;
	for(int i=0;i<zq1;i++) cin>>t[i];
	for(int i=0;i<n;i++) d1[i]=t[i%zq1];
	for(int i=0;i<zq2;i++) cin>>t[i];
	for(int i=0;i<n;i++) d2[i]=t[i%zq2];
//	for(int i=0;i<n;i++){
//		cout<<i<<":"<<d1[i]<<" "<<d2[i]<<endl;
//	}
	for(int i=0;i<n;i++)
	if(sheet[d1[i]][d2[i]]==1) ans1++;
	else if(sheet[d1[i]][d2[i]]==-1) ans2++;
	cout<<ans1<<' '<<ans2;
	return 0;
}
