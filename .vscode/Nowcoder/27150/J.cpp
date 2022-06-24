#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
#define MAXM 800005
typedef pair<ll,ll> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define per(i,x,y) for(ll i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll head[MAXN];ll tot;
struct EDGE
{
    ll to,next,val;
}edge[MAXM];
void add_edge(ll from,ll to,ll val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
ll m,s,e;//点的数量
ll dis[MAXN];//存储所有点到一号点的距离
int vis[MAXN];
vector <ll> num;
ll opt[MAXN], u[MAXN], v[MAXN], l[MAXN];
int findx(ll x)  {return lower_bound(num.begin(), num.end(), x) - num.begin() ;}
//求一号点到n号点的最短距离，如果不存在，则返回-1
ll dij()
{
    memset(dis, 0x3f, sizeof dis);
    s = findx(s);
    dis[s] = 0;
    priority_queue <pii,vector<pii>,greater<pii>> q;
    q.push({dis[s],s});
    while (q.size())
    {
        ll now = q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            int val = edge[i].val;
            if (dis[to] > dis[now] + val)
            {
                dis[to] = dis[now] + val;
                q.push({dis[to], to});
            }
        }
    }

    e = findx(e);
    return dis[e];
}
void solve()
{
    ll speed;   
    m = read(), s = read(), e = read(), speed = read();
    num.pb(s), num.pb(e);
    for (int i = 1; i <= m; i ++)
    {
        u[i] = read(), v[i] = read(), l[i] = read(), opt[i] = read();
        num.pb(u[i]), num.pb(v[i]);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= m; i ++)
    {
        int x = findx(u[i]);
        int y = findx(v[i]);
        add_edge(x, y, l[i]);
        if (opt[i] == 2)
            add_edge(y, x, l[i]);
    }
    ll ans = dij();
    if (ans == INF)
    {
        puts("-1");
        return;
    }
    printf("%lld\n", (ans + speed - 1) / speed);
}

int main()
{
    solve();
    return 0;
}