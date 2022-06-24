#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005
#define rep(i,x,y) for(int i=x;i<=y;i++)
int head[MAXN],h[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int h[],int from,int to)
{
    edge[++tot].to=to;edge[tot].next=h[from];h[from]=tot;
}

ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll n,m;
ll a[MAXN];
int dfn[MAXN],low[MAXN],num,key[MAXN],scc,sccc[MAXN];
int vis[MAXN];stack <int> st;

void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    vis[x]=1;st.push(x);
    for(int i=h[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y]==1)
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x])
    {
        scc++;
        int now=-1;
        while(x!=now)
        {
            now=st.top();st.pop();
            vis[now]=0;
            key[now]=scc;
            sccc[scc]+=a[now];
        }
    }
}
int indgr[MAXN];
void work()
{
    for(int now=1;now<=n;now++)
    {
        for(int i=h[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(key[now]==key[to]) continue;
            add_edge(head,key[now],key[to]);
            indgr[key[to]]++;
        }
    }
}
ll ans=0;
ll dp[MAXN];

void topu()
{
    queue <int> q;
    rep(i,1,scc)
    {
        if(!indgr[i])
        {
            q.push(i);
            dp[i]=sccc[i];
        }
    }
    while(q.size())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            dp[to]=max(dp[to],dp[now]+sccc[to]);
            indgr[to]--;
            if(!indgr[to]) q.push(to);
        }
    }
    ll mx=0;
    rep(i,1,scc)
        mx=max(mx,dp[i]);
    cout<<mx<<endl;
}


void solve()
{
    n=read(),m=read();
    rep(i,1,n) key[i]=i;
    rep(i,1,n) a[i]=read();
    rep(i,1,m)
    {
        ll u=read(),v=read();
        add_edge(h,u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    //rep(i,1,n) cout<<key[i]<<" ";
    work();
    topu();
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}