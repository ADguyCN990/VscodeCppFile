#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m,b,mx;//最大损血量
ll dis[MAXN];//扣得血量
int vis[MAXN];ll c[MAXN];//会受到的伤害
ll ans;
int head[MAXM];int cnt;
struct node
{
    int to,next;
    ll val;
}edge[MAXM];
void add_edge(int from,int to,ll val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        if(u==v) continue;
        add_edge(u,v,w);add_edge(v,u,w);
    }
}

bool check(ll mid)
{
    if(c[1]>mid||c[n]>mid) return false;
    for(int i=1;i<=n;i++)
    {
        if(c[i]<=mid)
            vis[i]=0;
        else
            vis[i]=1;
        dis[i]=INF;
    }
    dis[1]=0;
    priority_queue<pll> q;
    q.push({0,1});
    //边权是血量，最短路；点权是钱
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now])
            continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            ll val=edge[i].val;//要扣的血
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                q.push({-dis[to],to});
            }
        }
    }
    return dis[n]<=b;//如果血量扣到0以下，暴毙身亡
}

void solve()
{
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++) 
    {
        cin>>c[i];
        mx=max(mx,c[i]);
    }
    build();
    ans=INF;
    ll l=1;ll r=mx;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))//最多花mid合法，把r减小，试图花更少的钱
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(ans==INF)//花最多的钱依然会被打死
        cout<<"AFK"<<endl;
    else
        cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}