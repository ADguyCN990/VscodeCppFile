#include<bits/stdc++.h>
using namespace std;
#define MAXN 50005
#define ll long long
int tot;int head[MAXN];
struct node
{
    int to;int next;int val;
}edge[MAXN];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
ll n,m;
#define INF 114514114154
ll dis[MAXN];
int visit[MAXN];//标记是否在队列中
void spfa(int s,int n)
{
    queue <int> q;
    dis[s]=0;
    visit[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();visit[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int next=edge[i].to;
            int val=edge[i].val;
            if(dis[now]+val<dis[next])
            {
                dis[next]=dis[now]+val;
                if(visit[next]==0)
                {
                    visit[next]=1;
                    q.push(next);
                }
            }
        }
    }
    if(dis[n]==INF) cout<<-1<<endl;
    else cout<<-dis[n]<<endl;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        add_edge(u,v,-val);
    }
    for(int i=1;i<=n;i++) dis[i]=INF;
    spfa(1,n);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}