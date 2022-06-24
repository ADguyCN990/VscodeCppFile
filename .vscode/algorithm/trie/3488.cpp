#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXM 100005*32
#define MAXN 200005
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
ll n,m;
ll a[MAXN];
ll son[MAXM][15],cnt[MAXM],tot;
ll sum[MAXN];
void insert(ll x)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
        cnt[now]++;
    }
}

void update(ll x,ll y)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        now=son[now][u];
        cnt[now]+=y;
    }
}

ll query(ll x)
{
    int now=0;
    ll ans=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(son[now][!u]&&cnt[son[now][!u]])
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
    n=read(),m=read();
    ll ans=0;
    rep(i,1,n) a[i]=read(),sum[i]=sum[i-1]^a[i];
    insert(0);
    rep(i,1,n)
    {
        if(i>m) 
        {
            update(sum[i-m-1],-1);
        }
        insert(sum[i]);
        ans=max(ans,sum[i]^query(sum[i]));
    }
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
}