#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
ll siz[MAXN];//某点子树所有的节点数
ll fa[MAXN];
ll dis[MAXN];
int head[MAXN];int cnt=0;
ll n;
struct edge
{
    int to,next;
}edge[MAXN];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}

void dfs1(int now,int d)//第一次dfs求出所有节点的到各自子树的连边数量和1节点的dis
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa[now]) continue;
        fa[to]=now;
        siz[now]++;
        dfs1(to,d+1);
        siz[now]+=siz[to];
    }
    dis[1]+=d;
}

void dfs2(int now)
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==fa[now]) continue;
        dis[to]=dis[now]-(siz[to]+1)+n-(siz[to]+1);
        dfs2(to);
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);add_edge(v,u);
    }
    dfs1(1,0);
    //cout<<dis[1]<<endl;
    dfs2(1);
    int mn=dis[1];int minid=1;
    for(int i=2;i<=n;i++)
    {
        if(dis[i]<mn)
        {
            minid=i;
            mn=dis[i];
        }
    }
    cout<<minid<<" "<<mn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}