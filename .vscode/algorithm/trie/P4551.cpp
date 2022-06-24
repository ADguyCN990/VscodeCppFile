#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
ll a[MAXN];//每个节点到根节点的异或和
ll cnt,son[MAXN*32][2];
ll ans,n;

void dfs(int now,int pre)//预处理出所有节点到根的异或和
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        ll val=edge[i].val;
        if(to==pre) continue;
        a[to]=a[now]^val;
        dfs(to,now);
    }
}

void insert(ll x)
{
    int now=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(!son[now][u])
            son[now][u]=++cnt;
        now=son[now][u];
    }
}

ll query(ll x)
{
    int now=0;
    ll ans=0;
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
    rep(i,1,n-1)
    {
        ll u,v,w;
        u=read(),v=read(),w=read();
        add_edge(u,v,w),add_edge(v,u,w);
    }
    dfs(1,0);
    rep(i,1,n) insert(a[i]);
    ll ans=0;
    rep(i,1,n)
    {
        ans=max(ans,a[i]^query(a[i]));
    }
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
}