#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
#define MAXM 5005+MAXN+MAXN
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int vis[MAXN],dis[MAXN];

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void spfa(int s)
{
    queue <int> q;
    memset(dis,-0x3f,sizeof(dis));dis[s]=0;
    vis[s]=1;q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]<dis[now]+val)
            {
                dis[to]=dis[now]+val;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=1;
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        add_edge(i,i-1,-1),add_edge(i-1,i,0);

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        add_edge(u-1,v,w);
    }
    spfa(0);
    ll ans=0;
    cout<<dis[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}