#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 1000005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int depth[MAXN],fa[MAXN][25];
int n,m,rt;
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

void build(int rt)
{
    memset(depth,0x3f,sizeof(depth));
    depth[0]=0;//哨兵
    depth[rt]=1;
    queue <int> q;q.push(rt);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            q.push(to);
            if(depth[to]>depth[now]+1)//to还没被搜索过
            {
                depth[to]=depth[now]+1;
                fa[to][0]=now;//to的上一层为now
                for(int k=1;k<=24;k++)
                {
                    fa[to][k]=fa[fa[to][k-1]][k-1];//向上更新
                }
            }
        }
    }
}

int lca(int x,int y)
{
    if(depth[x]<depth[y]) swap(x,y);
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
    cin>>n>>m>>rt;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);add_edge(v,u);
    }
    build(rt);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}