#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 4000005
#define INF 0x3f3f3f3f
#define mod 100003
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m;
ll dp[MAXN];
ll dis[MAXN];
int head[MAXM];int cnt;
int vis[MAXN];
struct node
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
}

void dij(int s)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    dp[s]=1;dis[s]=0;
    priority_queue <pll> q;
    q.push({0,1});
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now]) 
            continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=1;
            if(dis[to]>dis[now]+1)
            {
                dis[to]=dis[now]+1;
                dp[to]=dp[now];
                q.push({-dis[to],to});
            }
            else if(dis[to]==dis[now]+1)
            {
                dp[to]=(dp[now]+dp[to])%mod;
            }
        }

    }

}

void output()
{
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<endl;
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