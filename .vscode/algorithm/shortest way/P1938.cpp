#include<bits/stdc++.h>
using namespace std;
#define MAXN 225
#define MAXM 100005
int vis[MAXN];
int head[MAXN];int tot;
int cnt[MAXN];//判"负"环
int dis[MAXN];
int w,m1,n,m2,s;
struct node
{
    int next,to,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void spfa(int s)
{
    queue <int> q;
    vis[s]=1;dis[s]=w;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]<dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n)
                {
                    cout<<"-1"<<endl;
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
    cin>>w>>m1>>n>>m2>>s;
    for(int i=1;i<=m1;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v,w);
    }
    for(int i=1;i<=m2;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        add_edge(u,v,w-t);
    }
    spfa(s);
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dis[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}