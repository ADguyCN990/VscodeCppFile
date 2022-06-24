#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<ll,int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll dis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
int a[MAXN];
int n, m;
bool vis[MAXN];
void dij(int s)
{
    for (int i = 1; i <= n; i ++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dis[s], s});
    while (q.size())
    {
        int now = q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (dis[to] > dis[now] + val)
            {
                dis[to] = dis[now] + val;
                q.push({dis[to], to}); 
            }
        }
    }
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        u = read(), v = read();
        if (a[u] > a[v]) add_edge(u, v, 0);
        else add_edge(u, v, a[v] - a[u]);
        if (a[v] > a[u]) add_edge(v, u, 0);
        else add_edge(v, u, a[u] - a[v]);
    }
    dij(1);
    ll mx = 0;
    // for (int i = 1; i <= n; i ++)
    //     printf("%d\n", dis[i]);
    for (int i = 1; i <= n; i ++)
    {
        mx = max(mx, a[1] - a[i] - dis[i]);
    }
    printf("%lld\n", mx);
}

int main()
{
    solve();
    return 0;
}