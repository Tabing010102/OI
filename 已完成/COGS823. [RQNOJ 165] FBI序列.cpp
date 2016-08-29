#include<cstdio>
#include<cstring>
using namespace std;
int i[2005];
char s[2005];
int main(){
	freopen("fbi.in","r",stdin);
	freopen("fbi.out","w",stdout);
	scanf("%s",s); int len=strlen(s);
	for(int j=0;j<len;j++)
		if(s[j]=='I') i[j]++;
	for(int j=len-1;j>=0;j--) i[j]+=i[j+1];
	int ans=0;
	for(int j=0;j<len;j++) if(s[j]=='F')
		for(int k=j+1;k<len;k++)
			if(s[k]=='B') ans+=i[k+1];
	printf("%d",ans);
	return 0;
}
