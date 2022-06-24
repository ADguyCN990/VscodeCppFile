#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 100005
#define INF 0x3f3f3f3f
#define mp make_pair
typedef pair<int,pair<int,int>> pii;
int n,m,s,e;
int tot;int head[MAXN];
struct node
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
int cnt[MAXN][2];//0表示最短路的个数，1表示次短路的个数
int dis[MAXN][2];//0表示s到i的最短路的长度，1表示s到i的次短路的长度
int vis[MAXN][2];
void init()
{
    tot=0;
    memset(head,0,sizeof(head));
}

int dij(int s,int e)
{
    priority_queue <pii> q;//距离，类型，编号
    for(int i=1;i<=n;i++)
    {
        dis[i][0]=INF;
        dis[i][1]=INF;
        vis[i][0]=0;
        vis[i][1]=0;
        cnt[i][1]=0;
        cnt[i][0]=0;
    }
    dis[s][0]=0;cnt[s][0]=1;
    q.push({dis[s][0],mp(0,s)});
    while(!q.empty())
    {
        int now=q.top().second.second;
        int type=q.top().second.first;
        int d=dis[now][type];
        q.pop();
        if(vis[now][type]) continue;
            vis[now][type]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to][0]>d+val)//找到了一条新的最短路
            {
                dis[to][1]=dis[to][0];
                dis[to][0]=d+val;
                cnt[to][1]=cnt[to][0];//原先的最短路变成了次短路
                cnt[to][0]=cnt[now][type];
                q.push({-dis[to][1],mp(1,to)});
                q.push({-dis[to][0],mp(0,to)});
            }
            else if(dis[to][0]==d+val)
            {
                cnt[to][0]+=cnt[now][type];
            }
            else if(dis[to][1]>d+val)//大于最短路但是小于次短路
            {
                dis[to][1]=d+val;
                cnt[to][1]=cnt[now][type];
                q.push({-dis[to][1],mp(1,to)});
            }
            else if(dis[to][1]==d+val)
            {
                cnt[to][1]+=cnt[now][type];
            }
        }
    }
    int ans=cnt[e][0];
    if(dis[e][0]+1==dis[e][1])
        ans+=cnt[e][1];
    return ans;
}

void solve()
{
    init();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    cin>>s>>e;
    cout<<dij(s,e)<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"dis0: "<<dis[i][0]<<" dis1: "<<dis[i][1]<<endl;
    //     cout<<"cnt0: "<<cnt[i][0]<<" cnt1: "<<cnt[i][1]<<endl;
    // }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}