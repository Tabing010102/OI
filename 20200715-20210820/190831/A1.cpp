#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uu unsigned
 
struct node
{
    int id;
    int val;
};
 
stack <node> stk1;
stack <int> stk2;
ll p,q,m;
uu SA,SB,SC;
int n;
 
uu rng61()
{
    uu t;
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    t=SA,SA=SB,SB=SC,SC^=t^SA;
    return SC;
}
 
ll gen()
{
    node tmp;
    ll res,ans;
    int i;
    while(!stk1.empty()) stk1.pop();
    while(!stk2.empty()) stk2.pop();
    scanf("%d%lld%lld%lld%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    ans=0;
    for(i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p)
        {
            res=(ll)rng61()%m+1;
            if(stk1.empty()||stk1.top().val<res)
            {
                tmp.id=i;
                tmp.val=res;
                stk1.push(tmp);
            }
            stk2.push(i);
        }
        else
        {
            if(!stk2.empty())
            {
                if(!stk1.empty()&&stk1.top().id==stk2.top())
                {
                    stk1.pop();
                }
                stk2.pop();
            }
        }
        if(!stk1.empty()) ans^=(stk1.top().val*(ll)i);
    }
    return ans;
}
 
int main()
{
    int t,cas;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        printf("Case #%d: %lld\n",cas,gen());
    }
    return 0;
}
