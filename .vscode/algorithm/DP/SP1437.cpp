#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int head[MAXN];int cnt;
int dis[MAXN];
int deepest;
struct edge
{
    int next,to;
}edge[MAXN];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

void dfs1(int now,int fa)
{
    if(now==fa) return;
    dis[now]=dis[fa]+1;
    if(dis[now]>dis[deepest]) deepest=now;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa) continue;
        dfs1(to,now);
    }
}

ll n;
void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);add_edge(v,u);
    }
    dfs1(1,0);dfs1(deepest,0);
    cout<<dis[deepest]-1<<endl;//无根树，假设了一个根，深度应该减1
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}