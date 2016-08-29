#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=200010;
const int MOD=10007;
vector<int> G[maxn];
vector<int>::iterator it;
int n,w[maxn],maxv,total;
inline int sqr(int x){
	return x*x;
}
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
}
void work(int now){
	int max1=-1,max2=-1;//max1=G[now]���ڵ������е�һ���Ȩֵmax2�ڶ���
	int sum=0;//sum��G[now]���ڵ�����Ȩֵ�ĺ�
	for(it=G[now].begin();it!=G[now].end();it++){
		sum+=w[*it]; sum%=MOD;//��
		if(w[*it]>max2)
			if(w[*it]>max1){//w[*it]���������� 
				max2=max1;
				max1=w[*it];
			}else max2=w[*it];//w[*it]ֻ��max2�� 
	}
	for(it=G[now].begin();it!=G[now].end();it++){
		total+=sum*w[*it]-sqr(w[*it]); total%=MOD;//�ų�w[*it]����
		maxv=max(maxv,max1*max2); 
	}
}
int main(){
	freopen("linkb.in","r",stdin);
	freopen("linkb.out","w",stdout);
	init();
	for(int i=1;i<=n;i++) work(i);
	printf("%d %d",maxv,total);
	return 0;
}
