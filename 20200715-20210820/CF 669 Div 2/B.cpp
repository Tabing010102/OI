#include<map>
#include<queue>
#include<time.h>
#include<limits.h>
#include<cmath>
#include<ostream>
#include<iterator>
#include<set>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep_1(i,m,n) for(int i=m;i<=n;i++)
#define mem(st) memset(st,0,sizeof st)
inline int read()
{
	int num=0, w=0;
	char ch=0;
	while (!isdigit(ch))
	{
		w|=ch=='-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		num = (num<<3) + (num<<1) + (ch^48);
		ch = getchar();
	}
	return w? -num: num;
}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef pair<double,double> pdd;
const int inf = 0x3f3f3f3f;
const int N=1010;
int a[N];
int b[N];
bool st[N];
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	memset(st,0,sizeof  st);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	b[1]=a[1];
	int ans=a[1];
	for(int i=2;i<=n;i++)
	{
		int res=1;
		int poj=-1;
		for(int j=2;j<=n;j++)
		{
			if(res<=__gcd(ans,a[j])&&st[j]==0)
			{
				res=__gcd(ans,a[j]);
				poj=j;
			}
		}
		st[poj]=1;
		b[i]=a[poj];
		ans=res;
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

