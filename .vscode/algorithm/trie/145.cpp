#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 100005*31
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
ll n;
ll a[MAXN];
ll son[MAXM][2],tot;

void insert(ll x)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
        {
            son[now][u]=++tot;
        }
        now=son[now][u];
    }
}

ll query(ll x)
{
    ll ans=0;
    ll now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(son[now][!u])
        {
            ans=ans*2+!u;
            now=son[now][!u];
        }
        else
        {
            ans=ans*2+u;
            now=son[now][u];
        }
        
    }
    return ans;
}

void solve()
{
    n=read();
    rep(i,1,n) a[i]=read();
    ll ans=0;
    rep(i,1,n)
    {
        insert(a[i]);
        ll b=query(a[i]);
        ans=max(ans,a[i]^b);
    }
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
}