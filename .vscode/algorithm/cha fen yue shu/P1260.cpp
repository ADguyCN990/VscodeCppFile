#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MAXM 10005
#define INF 0x3f3f3f3f
int n,m;
int vis[MAXN],cnt[MAXN],dis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

bool spfa(int s)
{
    for(int i=0;i<=n;i++)
    {
        vis[i]=0,dis[i]=INF,cnt[i]=0;
    }
    vis[s]=1;dis[s]=0;
    queue <int> q;q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n+1)
                    return false;
                if(!vis[to])
                    q.push(to),vis[to]=1;
            }
        }
    }
    return true;
}

void solve()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        add_edge(0,i,0);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(v,u,w);
    }
    bool flag=spfa(0);
    int mn=INF;
    if(!flag)
        cout<<"NO SOLUTION"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            mn=min(mn,dis[i]);
        for(int i=1;i<=n;i++)
        {
            cout<<dis[i]-mn<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}