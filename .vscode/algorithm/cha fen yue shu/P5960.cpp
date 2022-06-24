#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define MAXM 5005+5005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;

int head[MAXN];int tot;
int cnt[MAXN],vis[MAXN],dis[MAXN];
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
        cnt[i]=0,vis[i]=0,dis[i]=INF;
    }
    vis[s]=1;dis[s]=0;q.push(s);
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
                {
                    q.push(to);
                    vis[to]=1;
                }
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
    if(!flag)
        cout<<"NO"<<endl;
    else
        for(int i=1;i<=n;i++)
            cout<<dis[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}