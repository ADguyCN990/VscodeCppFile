#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 2005
#define MAXM 2005*2005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m;
int vis[MAXN];ll dis[MAXN];ll dp[MAXN];
int mp[MAXN][MAXN];
int head[MAXM];int cnt;
struct node
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        if(mp[u][v]==0)
        {
            add_edge(u,v,val);
            mp[u][v]=cnt;
        }        
        else
        {
            if(val<edge[mp[u][v]].val)
            {
                edge[mp[u][v]].val=val;
            }
        }
    }
}

void dij(int s)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;dp[s]=1;
    priority_queue <pll> q;
    q.push({dis[s],s});
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now])
            continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                dp[to]=dp[now];
                q.push({-dis[to],to});
            }
            else if(dis[to]==dis[now]+val)
                dp[to]+=dp[now];
        }
    }
}

void output()
{
    if(dis[n]==INF) cout<<"No answer"<<endl;
    else cout<<dis[n]<<" "<<dp[n]<<endl;
}

void solve()
{
    cin>>n>>m;
    build();
    dij(1);
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}