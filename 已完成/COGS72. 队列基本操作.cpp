#include<cstdio>
using namespace std;
int n,que[30000000],head=0,tail=0;
FILE *fin,*fout;
void work(int op,int v){
	if(op==1){
		tail=head;
	}else if(op==2){
		if(tail-head>=10) fprintf(fout,"queue out\n");
		else que[tail++]=v;
	}else if(op==3){
		if(head==tail) fprintf(fout,"queue empty\n");
		else head++;
	}else{
		fprintf(fout,"%d\n",tail-head);
		for(int i=head;i<tail;i++)
			fprintf(fout,"%d ",que[i]);
		fprintf(fout,"\n");
	}
}
int main(){
	fin=fopen("queue.in","r");
	fout=fopen("queue.out","w");
//	fout=stdout;
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++){
		int op,v=0;
		fscanf(fin,"%d",&op);
		if(op==2) fscanf(fin,"%d",&v);
		work(op,v);
//		fprintf(fout,"\n");
	}
	return 0;
}
