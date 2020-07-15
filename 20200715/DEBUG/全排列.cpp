#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int main()
{
	char ch[10];
	int m;
	gets(ch);
	m=strlen(ch);
	sort(ch,ch+m);
	do
    {
        for(int i=0;i<=m;i++)
        	cout<<ch[i];
        cout<<endl;
    }
    while( next_permutation(ch,ch+m) ); 
}
