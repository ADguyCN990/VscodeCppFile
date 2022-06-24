#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM MAXN*32
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int opt,n;
int son[MAXM][2],tot=1,cnt[MAXM];

void update(ll x,ll y)
{
    int now=1;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
        cnt[now]+=y;
    }
}

ll query(int x,int y)
{
    ll ans=0;
    int now=1;
    for(int i=31;i>=0;i--)
    {
        int ux=(x>>i)&1;
        int uy=(y>>i)&1;
        if(ux==0&&uy==1)
        {
            ans+=cnt[son[now][0]];
        }
        if(ux==1&&uy==1)
        {
            ans+=cnt[son[now][1]];
        }
        if(uy==0)
        {
            if(cnt[son[now][ux]])
                now=son[now][ux];
            else
                break;
        }
        else
        {
            if(cnt[son[now][!ux]])
                now=son[now][!ux];
            else
                break;
        }
    }
    return ans;
}

void solve()
{
    n=read();
    while(n--)
    {
        opt=read();
        if(opt==1)
        {
            int x;
            x=read();
            update(x,1);
        }
        else if(opt==2)
        {
            int x;
            x=read();
            update(x,-1);
        }
        else
        {
            int x,y;
            x=read(),y=read();
            printf("%lld\n",query(x,y));
        }
    }
}

int main()
{
    solve();
    return 0;
}