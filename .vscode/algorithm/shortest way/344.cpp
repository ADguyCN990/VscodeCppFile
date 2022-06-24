#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25005
#define MAXM 200005
#define INF 0x3f3f3f3f
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
ll n,m1,m2,s;
queue <int> qq;
int head[MAXM];int cnt;
struct node
{
    ll to,next,val;
}edge[MAXM];
void add_edge(ll from,ll to,ll val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

int key[MAXM];//每个点属于哪个连通块
vector <int> block[MAXN];//每个连通块内包含的点的信息
int tot;//连通块的个数
int indgr[MAXN];int vis[MAXN];ll dis[MAXN];
void dfs(int now)
{
    key[now]=tot;
    block[tot].emplace_back(now);
    for(int i=head[now];i;i=edge[i].next)
    {
        ll to=edge[i].to;
        if(!key[to])
            dfs(to);
    }
}

void pre()//根据路线维护连通块信息
{
    for(int i=1;i<=m1;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);add_edge(v,u,w);
    }
    for(int i=1;i<=n;i++)
    {
        if(!key[i])//i还未加入连通块
        {
            tot++;
            dfs(i);
        }
    }
}

void build()
{
    pre();
    for(int i=1;i<=m2;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        indgr[key[v]]++;
    }
}

void dij(int id)//id为连通块编号
{
    priority_queue <pll> q;
    for(auto x:block[id])
        q.push({-dis[x],x});
    while(!q.empty())
    {
        ll now=q.top().second;q.pop();
        if(vis[now]) 
            continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            ll to=edge[i].to;
            ll val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                if(key[to]==key[now])//只有在一个连通块内才能进行dij操作
                q.push({-dis[to],to});
            }
            if(key[to]!=key[now])
            {
                indgr[key[to]]--;
                if(!indgr[key[to]])
                    qq.push(key[to]);
            }
        }
    }
}

void work(int s)//整体跑拓扑序
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=INF;
    }   
    dis[s]=0;qq.push(key[s]);
    for(int i=1;i<=tot;i++)
    {
        if(indgr[i]==0)
            qq.push(i);
    }
    while(!qq.empty())
    {
        int now=qq.front();qq.pop();
        dij(now);
    }

}

void output()
{
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>=1e9)
            cout<<"NO PATH"<<endl;
        else
            cout<<dis[i]<<endl;
    }
}

void solve()
{
    cin>>n>>m1>>m2>>s;
    build();
    work(s);
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}