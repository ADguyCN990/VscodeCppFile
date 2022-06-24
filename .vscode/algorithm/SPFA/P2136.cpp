#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 10005
#define INF 0x3f3f3f3f
int dis[MAXN];
int cnt[MAXN];int vis[MAXN];
int head[MAXN];int tot;
int n,m;   
struct edge
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void spfa(int s)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=INF;
        cnt[i]=0;
    }
    queue <int> q;vis[s]=1;dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n)
                {
                    cout<<"Forever love"<<endl;
                    exit (0);
                }
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
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
        add_edge(u,v,-w);
    }
    int ans=INF;
    spfa(1);
    ans=min(ans,dis[n]);
    spfa(n);
    ans=min(ans,dis[1]);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}