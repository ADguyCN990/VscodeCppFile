#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 2*MAXN
int dis[MAXN];//到根节点的距离
int n,m,depth[MAXN],fa[MAXN][25];
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
    for(int i=head[now];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==pre) continue;
        dis[to]=dis[now]+edge[i].val;
        dfs(to,now);
    }
}

void build(int rt)
{
    memset(depth,0x3f,sizeof(depth));
    depth[0]=0;depth[rt]=1;
    queue <int> q;q.push(rt);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            if(depth[to]>depth[now]+1)
            {
                depth[to]=depth[now]+1;
                q.push(to);
                fa[to][0]=now;
                for(int k=1;k<=24;k++)
                {
                    fa[to][k]=fa[fa[to][k-1]][k-1];
                }
            }
        }
    }
}

int lca(int x,int y)
{
    if(depth[x]<depth[y])   swap(x,y);
    for(int k=24;k>=0;k--)
    {
        if(depth[fa[x][k]]>=depth[y])
            x=fa[x][k];
    }
    if(x==y) return x;
    for(int k=24;k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}

void solve()
{
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w),add_edge(v,u,w);
    }
    dfs(1,-1);
    build(1);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<0<<endl;
            continue;
        }
        int f=lca(x,y);
        cout<<dis[x]+dis[y]-2*dis[f]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}