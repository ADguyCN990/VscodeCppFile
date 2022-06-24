#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 20005
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m,k;
ll mx;
ll dis[MAXN];//从1到i的最短路中长度大于mid的电话线的个数
int vis[MAXN];
ll ans=-1;

int head[MAXM];int cnt;
struct edge
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        add_edge(u,v,val);add_edge(v,u,val);
        mx+=val;
    }
}

bool check(ll mid)//枚举有多少边的长度大于mid
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    dis[1]=0;
    priority_queue<pll> q;
    q.push({0,1});
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now])
            continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            ll val=edge[i].val;
            if(val>mid)
                val=1;
            else
                val=0;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                q.push({-dis[to],to});
            }
        }
    }
    return dis[n]<=k;
}

void solve()
{
    cin>>n>>m>>k;
    build();
    ll l=0;ll r=mx;
    while(l<=r)//最短路的最大值,l为可行区间
    {
        ll mid=(l+r)/2;
        if(check(mid))//假设最长距离为mid，大于mid的免费，小于mid的不用管，统计大于mid的个数和k的关系
        {
            ans=mid;
            r=mid-1;
        }
        else 
            l=mid+1;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}