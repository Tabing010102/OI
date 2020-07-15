#include<iostream>
#include<algorithm>
using namespace std;

struct point{
	int data;
	int num;
}a[10000];

bool cmp(point x,point y){
	return x.data>y.data;
}

int main(){
	int n=0;
//	freopen("in9.txt","r",stdin);
//	freopen("out9.txt","w",stdout);
	int s[10000];
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i].data);
		a[i].num=i;
	}
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++){
		s[a[n-i-1].num]=a[i].data;
	}
	for (int i=0;i<n;i++)
		printf("%d ",s[i]);
}
