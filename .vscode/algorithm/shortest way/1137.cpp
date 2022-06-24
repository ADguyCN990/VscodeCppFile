#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXM 200005
#define MAXN 200005
#define INF 0x3f3f3f3f
ll n,m;
int a,b,c,d,e;
ll dis[10][MAXN];
typedef pair<ll,ll> pll;
ll ans=0x3f3f3f3f;
map <int,int> mp;
int head[MAXM];int vis[MAXN];int cnt;
struct node
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
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
}

void dij(int s)
{
    //起点为mp[s]
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[mp[s]][i]=INF;
    }
    dis[mp[s]][s]=0;
    priority_queue <pll> q;
    q.push({0,s});
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[mp[s]][to]>dis[mp[s]][now]+val)
            {
                dis[mp[s]][to]=dis[mp[s]][now]+val;
                q.push({-dis[mp[s]][to],to});
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    cin>>a>>b>>c>>d>>e;
    vector <int> v;
    v.emplace_back(1);v.emplace_back(a);v.emplace_back(b);v.emplace_back(c);v.emplace_back(d);v.emplace_back(e);
    mp[1]=1;mp[a]=2;mp[b]=3;mp[c]=4;mp[d]=5;mp[e]=6;
    build();
    for(int i=0;i<v.size();i++)
        dij(v[i]);
    for(int i=2;i<=6;i++)
    {
        for(int j=2;j<=6;j++)
        {
            for(int k=2;k<=6;k++)
            {
                for(int ii=2;ii<=6;ii++)
                {
                    for(int jj=2;jj<=6;jj++)
                    {
                        if((1<<i)+(1<<j)+(1<<k)+(1<<ii)+(1<<jj)==124)//五个数都不相同
                        {
                            ans=min(ans,dis[1][v[i-1]]+dis[i][v[j-1]]+dis[j][v[k-1]]+dis[k][v[ii-1]]+dis[ii][v[jj-1]]);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}