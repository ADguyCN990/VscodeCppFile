#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define MAXM MAXN*3
#define INF 0x3f3f3f3f
int n,m;
int dis[MAXN],vis[MAXN],cnt[MAXN];

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
        dis[i]=INF,vis[i]=0,cnt[i]=0;
    }
    dis[s]=0;vis[s]=1;
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
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        add_edge(0,i,0);
    for(int i=1;i<=m;i++)
    {
        int f;
        cin>>f;
        if(f==1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            add_edge(u,v,-w);
        }
        else if(f==2)
        {
            int u,v,w;
            cin>>u>>v>>w;
            add_edge(v,u,w);
        }
        else if(f==3)
        {
            int u,v;
            cin>>u>>v;
            add_edge(u,v,0),add_edge(v,u,0);
        }
    }
    bool flag=spfa(0);
    if(flag)
        cout<<"Yes"<<endl;
    else    
        cout<<"No"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}