#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 2000005
typedef pair<int,int> pii;
int mod;
int n,m;
ll dp[MAXN],cnt[MAXN];//包含节点的个数，方案的个数，经典统计方案
int head[MAXN];int hh[MAXN];int tot;
int vis[MAXN],dfn[MAXN],low[MAXN],sccc[MAXN],key[MAXN],indgr[MAXN],num,scc;//强联通分量维护强联通分量节点的个数
stack <int> st;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int h[],int from,int to)
{
    edge[++tot].to=to;edge[tot].next=h[from];h[from]=tot;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    st.push(x);vis[x]=1;
    for(int i=hh[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y])
        {
            low[x]=min(dfn[y],low[x]);
        }
    }
    if(low[x]==dfn[x])
    {
        scc++;
        int now=-1;
        while(now!=x)
        {
            now=st.top();st.pop();
            vis[now]=0;
            key[now]=scc;
            sccc[scc]++;
        }
    }
}

void build()
{
    set <ll> s;
    for(int now=1;now<=n;now++)
    {
        for(int i=hh[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(key[now]==key[to]) continue;
            ll hash = key[now] * 1000000ll + key[to];
            if(s.count(hash)) continue;//判重边
            add_edge(head,key[now],key[to]);
            indgr[key[to]]++;
            s.insert(hash);
        }
    }
}

void topu()
{   queue <int> q;
    for(int i=1;i<=scc;i++)
    {
        if(indgr[i]==0)
        {
            dp[i]=sccc[i];
            cnt[i]=1;
            q.push(i);
        }
        
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=sccc[to];
            if(dp[to]==dp[now]+val)
            {
                cnt[to]=(cnt[to]+cnt[now])%mod;
            }
            else if(dp[to]<dp[now]+val)
            {
                dp[to]=dp[now]+val;
                cnt[to]=cnt[now];
                
            }
            indgr[to]--;
            if(!indgr[to])
                q.push(to);
        }
    }
}

void output()
{
    int mx=-1;
    int mxcnt=0;
    for(int i=1;i<=scc;i++)
    {
        if(dp[i]>mx)
        {
            mx=dp[i];
            mxcnt=cnt[i];
        }
        else if(dp[i]==mx)
        {
            mxcnt=(mxcnt+cnt[i])%mod;
        }
    }
    cout<<mx<<endl;
    cout<<mxcnt<<endl;
}

void solve()
{
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++)
        key[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(hh,u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    build();
   
    topu();
   
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}