#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring> 

using namespace std;

struct Point{
	int x,y;
};

const double eps=1e-4;
int n,CityNum,FlyCost,A,B;
double d[410][410];//G[i*4+j]编号为i的城市第j个点(0<=j<=3)
Point G[110][4];//原图

inline double CalcDist(int xi1,int yi1,int xi2,int yi2,int cost=1){
	return (double)cost*(sqrt(abs(xi1-xi2)*abs(xi1-xi2)+abs(yi1-yi2)*abs(yi1-yi2)));
}
void FindAnotherPoint(int xi1,int yi1,int xi2,int yi2,int xi3,int yi3,int& xi4,int& yi4){
	double d12=CalcDist(xi1,yi1,xi2,yi2);
	double d23=CalcDist(xi2,yi2,xi3,yi3);
	double d13=CalcDist(xi1,yi1,xi3,yi3);
	if(d12*d12+d23*d23-d13*d13>=-eps&&d12*d12+d23*d23-d13*d13<=eps){//12,23垂直
		xi4=xi1+xi3-xi2; yi4=yi1+yi3-yi2;
	}else if(d12*d12+d13*d13-d23*d23>=-eps&&d12*d12+d13*d13-d23*d23<=eps){//12,13垂直 
		xi4=xi2+xi3-xi1; yi4=yi2+yi3-yi1;
	}else{//13,23垂直 
		xi4=xi1+xi2-xi3; yi4=yi1+yi2-yi3;
	}
}
void init(){
	cin>>CityNum>>FlyCost>>A>>B; A--; B--;
	memset(d,0x7f,sizeof(d)); memset(G,0,sizeof(G));
	for(int i=0;i<CityNum*4;i++) d[i][i]=0;
	for(int i=0;i<CityNum;i++){
		int cost,xi1,xi2,xi3,xi4,yi1,yi2,yi3,yi4;
		cin>>xi1>>yi1>>xi2>>yi2>>xi3>>yi3>>cost;
		FindAnotherPoint(xi1,yi1,xi2,yi2,xi3,yi3,xi4,yi4);
		//cout<<i<<":"<<"xi4="<<xi4<<" yi4="<<yi4<<endl;
		G[i][0]=(Point){xi1,yi1}; G[i][1]=(Point){xi2,yi2};
		G[i][2]=(Point){xi3,yi3}; G[i][3]=(Point){xi4,yi4};
		d[i*4+0][i*4+1]=d[i*4+1][i*4+0]=CalcDist(xi1,yi1,xi2,yi2,cost);
		d[i*4+0][i*4+2]=d[i*4+2][i*4+0]=CalcDist(xi1,yi1,xi3,yi3,cost);
		d[i*4+0][i*4+3]=d[i*4+3][i*4+0]=CalcDist(xi1,yi1,xi4,yi4,cost);
		d[i*4+1][i*4+2]=d[i*4+2][i*4+1]=CalcDist(xi2,yi2,xi3,yi3,cost);
		d[i*4+1][i*4+3]=d[i*4+3][i*4+1]=CalcDist(xi2,yi2,xi4,yi4,cost);
		d[i*4+2][i*4+3]=d[i*4+3][i*4+2]=CalcDist(xi3,yi3,xi4,yi4,cost);
	}
	for(int i=0;i<CityNum;i++) for(int j=i+1;j<CityNum;j++) for(int a=0;a<4;a++) for(int b=0;b<4;b++)
	d[i*4+a][j*4+b]=d[j*4+b][i*4+a]=CalcDist(G[i][a].x,G[i][a].y,G[j][b].x,G[j][b].y,FlyCost);
	/*for(int i=0;i<CityNum*4;i++){
		for(int j=0;j<CityNum*4;j++)
			if(d[i][j]>1e5) printf("inf ");
			else printf("%.1lf ",d[i][j]);
		cout<<endl;
	}*/
}
void floyd(int n){
	for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++)
	if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
}

int main(){
	freopen("cardlxlx.in","r",stdin);
	freopen("cardlxlx.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		init();
		/*for(int i=0;i<CityNum*4+4;i++){
			for(int j=0;j<CityNum*4+4;j++)
				if(d[i][j]>1e5) printf(" inf ");
				else printf("%4.1lf ",d[i][j]);
			cout<<endl;
		}*/
		floyd(CityNum*4); double minn=d[A*4][B*4];
		for(int a=0;a<4;a++) for(int b=0;b<4;b++)
		if(minn>d[A*4+a][B*4+b]) minn=d[A*4+a][B*4+b];
		printf("%.1lf\n",minn);
	}
}
