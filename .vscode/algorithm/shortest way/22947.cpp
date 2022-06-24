#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 3005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
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
int n, nn, m;
int cnt[MAXN];
ll dis[MAXN];
int vis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
}

ll dij(int s)
{
    priority_queue <pii, vector<pii>, greater<pii>> q;
    init();
    dis[s] = 0;
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
            int val = edge[i].val;
            if (dis[to] > dis[now] + val)
            {
                dis[to] = dis[now] + val;
                q.push({dis[to], to});
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        ans += cnt[i] * dis[i];
    }
    return ans;
}

void solve()
{
    nn = read(), n = read(), m = read();
    for (int i = 1; i <= nn; i ++)
    {
        int tmp = read();
        cnt[tmp] ++;
    }
    for (int i = 1; i < m; i ++)
    {
        int u, v, w;
        u = read(), v = read(), w = read();
        add_edge(u, v, w), add_edge(v, u, w);
    }
    ll ans = INF;
    for (int i = 1; i <= n; i ++)
    {
        ll tmp = dij(i);
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}