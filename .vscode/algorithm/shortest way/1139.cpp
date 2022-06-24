#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005
#define INF 0x3f3f3f3f
typedef pair<ll,int> pli;
ll n,m,cnt_s,e;//点数量，边数量，起点数量，终点
ll ans=INF;
ll dis[MAXN];
int vis[MAXN];

int cnt;int head[MAXM];
struct node
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}   

void init()
{
    ans=INF;
    memset(head,-1,sizeof(head));
    memset(edge,0,sizeof(edge));
    cnt=0;
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int from,to,val;
        cin>>from>>to>>val;
        add_edge(from,to,val);
    }
}

ll dij(int s)
{
    for(int i=0;i<=n;i++) 
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[s]=0;
    priority_queue<pli> q;
    q.push({0,s});
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i!=-1;i=edge[i].next)
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
    return dis[e];
}

void solve()
{
    while(cin>>n>>m>>e)
    {
        init();
        build();
        cin>>cnt_s;
        for(int i=1;i<=cnt_s;i++)
        {
            int s;
            cin>>s;
            add_edge(0,s,0);
            //cout<<"start: s, dis= "<<dis[e]<<endl;
        }
        ans=dij(0);
        if(ans==INF) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}