#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 22005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m,mm;
int cnt[MAXN],vis[MAXN],dis[MAXN];
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
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF,vis[i]=0,cnt[i]=0;
    }
    q.push(s);dis[s]=0;vis[s]=1;
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
                    vis[to]=1,q.push(to);
            }
        }
    }
    return true;
}

void solve()
{
    memset(head,-1,sizeof(head));
    cin>>n>>m>>mm;
    for(int i=2;i<=n;i++)
        add_edge(i,i-1,0);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(u>v) swap(u,v);
        add_edge(u,v,w);
    }
    for(int i=1;i<=mm;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(u>v) swap(u,v);
        add_edge(v,u,-w);
    }
    int flag=spfa(n);
    if(!flag) 
        cout<<-1<<endl;
    else
    {
        spfa(1);
        if(dis[n]==INF)
            cout<<-2<<endl;
        else    
            cout<<dis[n]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}