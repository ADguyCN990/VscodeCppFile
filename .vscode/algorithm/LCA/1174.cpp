#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 40005
#define MAXM 2*MAXN
int n,m,rt;
int fa[MAXN][25],depth[MAXN];

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
    depth[0]=0;depth[rt]=1;
    queue <int> q;q.push(rt);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            
            if(depth[to]>depth[now]+1)
            {
                q.push(to);
                depth[to]=depth[now]+1;
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
    if(depth[x]<depth[y])  swap(x,y);
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
            y=fa[x][k];
        }
    }
    return fa[x][0];
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(v==-1) rt=u;
        else
            add_edge(u,v),add_edge(v,u);
    }
    build(rt);
    int m;
    cin>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        int ans=lca(u,v);
        if(ans==u)
            cout<<1<<endl;
        else if(ans==v)
            cout<<2<<endl;
        else
            cout<<0<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}