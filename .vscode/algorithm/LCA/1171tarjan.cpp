#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 20005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int f[MAXN],n,m,dis[MAXN],vis[MAXN];
vector <pii> mp[MAXN];//first存另一个点的编号，second存查询次数的编号
int ans[MAXM];//存储查询结果
int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
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

void dfs(int now,int pre)
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==pre) continue;
        dis[to]=dis[now]+edge[i].val;
        dfs(to,now);
    }
}

void tarjan(int now)
{   
    vis[now]=1;//表示正在搜索这个点
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])
            tarjan(to),f[to]=now;//合并到根节点
    }
    for(auto x:mp[now])
    {
        int to=x.first;
        int tim=x.second;
        if(vis[to]==2)//该点已完成回溯,LCA为f[to]
        {
            int fa=findx(to);
            ans[tim]=dis[now]+dis[to]-2*dis[fa];
        }
    }
    vis[now]=2;//该点已完成回溯
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u!=v)
        {
            mp[u].push_back({v,i});
            mp[v].push_back({u,i});
        }
    }
    tarjan(1);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}