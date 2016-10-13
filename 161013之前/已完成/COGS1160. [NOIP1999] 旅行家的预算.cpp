#include<cstdio>
using namespace std;
double d1,c,d2,p[210],d[210],ans;
int n;
int main(){
	freopen("lyuxing.in","r",stdin);
	freopen("lyuxing.out","w",stdout);
	scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p[0],&n);
	d[0]=0; d[n+1]=d1;
	for(int i=1;i<=n;i++) scanf("%lf%lf",&d[i],&p[i]);
	int now=0; double left=0; n++;
	while(now<=n){
		int far=now;//加满油最远到far 
		while(far<=n&&d[far+1]-d[now]<=c*d2) far++;
		if(far==now){//无解
			printf("No Solution");
			return 0; 
		}
		int ok=0;//是否有p[i]<p[now](i<=far) 
		for(int i=now+1;i<=far;i++) if(p[i]<p[now]){//找到p比p[now]的
			if(left*d2>=d[i]-d[now]){//剩下的油够用
				left-=(d[i]-d[now])/d2;
				now=i;
				ok=1;
				break; 
			}else{//不够用
				double needed=(d[i]-d[now])/d2;
				ans+=(needed-left)*p[now];
				left=0;
				now=i;
				ok=1;
				break;
			}
		}
		if(!ok){//在far范围内没有p[i]<p[now]
			int bestpos=9999999; double bestp=9999999;
			for(int i=now+1;i<=far;i++) if(p[i]<bestp){
				bestpos=i; bestp=p[i];
			}//找最小的p
			double needed=(d[bestpos]-d[now])/d2;
			ans+=(c-left)*p[now];//加满油冲过去
			left=c-needed;
			now=bestpos;
		}
	}
	printf("%.2lf",ans);
	return 0;
} 
