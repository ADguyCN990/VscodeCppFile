#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 200005
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;//估值函数+当前真实距离，当前真实距离，点编号
#define INF 0x3f3f3f3f
int n,m;
int s,e,k;
int vis[MAXN],dis[MAXN];
int cnt[MAXN];//剪枝玄学优化，能加速
int head[MAXN];int rhead[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int h[],int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=h[from];h[from]=tot;
}

void dij(int s)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(q.size())
    {
        int now=q.top().second;int distance=q.top().first;q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=rhead[now];i;i=edge[i].next)//有向边，反着遍历求最短路
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>distance+val)
            {
                dis[to]=distance+val;
                q.push({dis[to],to});
            }
        }
    }
}

int astar(int s,int e,int k)
{
    priority_queue<piii,vector<piii>,greater<piii>> q;
    q.push({dis[s],{0,s}});
    while(q.size())
    {
        int distance=q.top().second.first;
        int now=q.top().second.second;
        q.pop();
        cnt[now]++;
        if(cnt[e]==k) return distance;//此时的值为k短路
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(cnt[to]<k)//剪枝玄学优化
            q.push({dis[to]+distance+val,{distance+val,to}});
        }
    }
    return -1;//没有k短路
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(head,u,v,w),add_edge(rhead,v,u,w);
    }
    cin>>s>>e>>k;
    if(s==e) k++;

    dij(e);
    cout<<astar(s,e,k)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}