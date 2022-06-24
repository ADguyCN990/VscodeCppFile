#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 100005*25
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
int son[MAXM][15],tot,cnt[MAXM];
map <ll,ll> vis;//通过前缀和找到对应下标
ll sum[MAXN];
pair<ll,pii> ans;

void update(ll x,ll y)
{
    ll now=0;
    for(int i=21;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
        cnt[now]+=y;
    }
}

ll query(ll x)
{
    ll now=0;
    ll ans=0;
    for(int i=21;i>=0;i--)
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
    n=read();
    update(0,1);
    rep(i,1,n)
    {
        a[i]=read();
        sum[i]=sum[i-1]^a[i];
    }
    if(n==1&&a[1]==0)
    {
        printf("0 1 1\n");
        return;
    }
    rep(i,1,n)
    {
        if(vis.count(sum[i]))
        {
            update(sum[i],-1);
            vis[sum[i]]=i;
        }
        update(sum[i],i);
        ll tmp=query(sum[i]);
        if((tmp^sum[i])>ans.first)
        {
            ans.first=tmp^sum[i];
            ans.second.first=vis[tmp]+1;
            ans.second.second=i;
        }
        vis[sum[i]]=i;
    }
    printf("%lld %d %d\n",ans.first,ans.second.first,ans.second.second);
}

int main()
{
    solve();
    return 0;
}