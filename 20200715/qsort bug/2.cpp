#include<iostream>
using namespace std;

int a[100010];

void sort(int p,int q)
{
	int k,h,x=p,y=q;
	h=p+(q-p)/2;
	int dh=a[h];
	do
	{
		if(a[h] != dh) cout << "fxxk you" << endl;
		while (a[x]<a[h])	x++;
		while (a[y]>a[h])	y--;
		if (x<=y)
		{
			k=a[x];
			a[x]=a[y];
			a[y]=k;
			x++;
			y--;
		}
	}while (x<=y);
	if (x<q)	sort(x,q);
	if (y>p)	sort(p,y);
}

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(0,n-1);
	for (int i=0;i<n-1;i++)
		cout<<a[i]<<endl;
	cout<<a[n-1]<<endl;
}