#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m,L,R;
int dis[MAXN],vis[MAXN];
int flag[MAXM];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void dij(int s)
{
    priority_queue <pii> q;
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    q.push({dis[s],s});
    while(q.size())
    {
        int now=q.top().second;q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                q.push({-dis[to],to});
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>L>>R;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w),add_edge(v,u,w);
    }
    dij(0);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(dis[i]*2>=R) continue;//如果跑到一半就必须要回去了
        for(int j=head[i];j;j=edge[j].next)
            flag[j]=1;
    }
    for(int i=1;i<=tot;i+=2)
        cnt+=(flag[i]||flag[i+1]);//无向图
    cout<<cnt<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}