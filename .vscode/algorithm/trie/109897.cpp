#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3000005
#define MAXM 200005
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
ll son[MAXN][2],tot,cnt[MAXN*10];
ll a[MAXN];

void insert(ll x)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
        cnt[now]++;//统计x的贡献
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
        if(son[now][!u]&&cnt[son[now][!u]])//如果这个节点存在并且没有被删除掉
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
    rep(i,1,n) a[i]=read(),insert(a[i]);
    
    ll ans=0;
    rep(i,1,n)
    {
        rep(j,i+1,n)
        {
            update(a[i],-1),update(a[j],-1);
            ans=max(ans,(a[i]+a[j])^(query(a[i]+a[j])));
            update(a[i],1),update(a[j],1);
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
}