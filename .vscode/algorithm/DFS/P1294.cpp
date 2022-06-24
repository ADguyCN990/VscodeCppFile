#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
#define MAXM 105
int n,m;
int g[MAXN][MAXN];
int vis[MAXN];
ll ans=0;

void dfs(int now,ll sum)
{
    ans=max(ans,sum);
    for(int i=1;i<=n;i++)
    {
        if(g[now][i]&&!vis[i])
        {
            vis[i]=1;
            dfs(i,sum+g[now][i]);
            vis[i]=0;
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=w;
        g[v][u]=w;
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=1;
        dfs(i,0);
        vis[i]=0;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}