#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define MAXM 50005
#define ll long long
ll n,m;
ll dp[MAXN];

struct EDGE
{
    int to,next;
}edge[MAXM];
int head[MAXM],tot;
void add_edge1(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

int vis[MAXN],dfn[MAXN],scc,num,low[MAXN],key[MAXN],sccc[MAXN];
stack <int> st;
int outdgr[MAXN];

void tarjan(int x)
{
    low[x]=dfn[x]=++num;
    vis[x]=1;st.push(x);
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(dfn[y]==0)
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
        vector <int> v;
        while(now!=x)
        {
            now=st.top();st.pop();
            vis[now]=0;
            key[now]=scc;
            v.emplace_back(now);
            sccc[scc]++;
        }
        for(auto x:v)
        {
            for(int i=head[x];i;i=edge[i].next)
            {
                int y=edge[i].to;
                if(key[y]!=key[x]) outdgr[key[x]]++;
            }
        }
    }
}

void output()
{
    int ans=0;
    int cnt=0;
    for(int i=1;i<=scc;i++)
    {
        if(outdgr[i]==0)
        {
            cnt++;
            ans=sccc[i];
        }
    }
    if(cnt==1) cout<<ans<<endl;
    else cout<<0<<endl;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) key[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge1(u,v);
    }
    for(int i=1;i<=n;i++)
        if(dfn[i]==0)
            tarjan(i);
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}