#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 400005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int dis[MAXN];
int vis[MAXN];

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

int bfs(int s)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    queue <int> q;
    q.push(s);
    while(q.size())
    {
        int now=q.front();q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                q.push(to);
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
        mx=max(mx,dis[i]);
    return mx;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v,1),add_edge(v,u,1);
    }
    int mx=bfs(1);
    //cout<<mx<<endl;
    if(mx==INF)
        cout<<-1<<endl;
    else
        cout<<1+(int)(log2(mx)+0.999999)<<endl;//向上取整
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}