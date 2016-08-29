#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
int p1,p2,p3;
char s[100+10];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%s",&p1,&p2,&p3,s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='-'){
			if((isalpha(s[i-1])&&isalpha(s[i+1]))
			||(isdigit(s[i-1])&&isdigit(s[i+1]))){
                if(s[i-1]==s[i+1]-1) continue;
                else if(s[i-1]>=s[i+1]) putchar(s[i]);
                else{
					if(p3==1){//ÕýÐò
                        if(p1==3) for(int j=s[i-1]+1;j<=s[i+1]-1;j++) for(int k=1;k<=p2;k++) putchar('*');
						else{
							if(isdigit(s[i-1])) for(int j=s[i-1]+1;j<=s[i+1]-1;j++) for(int k=1;k<=p2;k++) putchar(j);
							else{//×ÖÄ¸
								if(p1==1) for(int j=s[i-1]+1;j<=s[i+1]-1;j++) for(int k=1;k<=p2;k++) putchar(j);
								else for(int j=s[i-1]+1;j<=s[i+1]-1;j++) for(int k=1;k<=p2;k++) putchar(toupper(j));
							}
						}
					}else{//µ¹Ðò
					    if(p1==3) for(int j=s[i+1]-1;j>=s[i-1]+1;j--) for(int k=1;k<=p2;k++) putchar('*');
						else{
							if(isdigit(s[i-1])) for(int j=s[i+1]-1;j>=s[i-1]+1;j--) for(int k=1;k<=p2;k++) putchar(j);
							else{//×ÖÄ¸
								if(p1==1) for(int j=s[i+1]-1;j>=s[i-1]+1;j--) for(int k=1;k<=p2;k++) putchar(j);
								else for(int j=s[i+1]-1;j>=s[i-1]+1;j--) for(int k=1;k<=p2;k++) putchar(toupper(j));
							}
						}
					}
                }
			}else putchar(s[i]);
		}else putchar(s[i]);
	}
	//system("pause");
	return 0;
}
