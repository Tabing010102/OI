#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
typedef long long LL;
struct Node{
	LL i,x,v;//i第i个(A/B/C[i])，第x个(f(x)) 
	bool operator<(const Node &rhs)const{
		return v>rhs.v;
	}
	Node(LL a,LL b,LL c){
		this->i=a;
		this->x=b;
		this->v=c;
	}
};
const LL maxn=500000+10;
LL n,m,A[maxn],B[maxn],C[maxn];
priority_queue<Node> pq;
fstream fin,fout;
LL f(LL i,LL x){return A[i]*x*x+B[i]*x+C[i];}
int main(){
	ios::sync_with_stdio(false);
	fin.open("minval.in",ios::in);
	fout.open("minval.out",ios::out);
	fin>>n>>m;
	for(LL i=0;i<n;i++){
		fin>>A[i]>>B[i]>>C[i];
		pq.push(Node(i,1,f(i,1)));
	}
	for(LL i=0;i<m;i++){
		Node tmp=pq.top(); pq.pop();
		fout<<tmp.v<<' ';
		pq.push(Node(tmp.i,tmp.x+1,f(tmp.i,tmp.x+1)));
	}
	return 0;
}
