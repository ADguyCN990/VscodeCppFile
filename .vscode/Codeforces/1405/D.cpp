#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
inline ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n, a, b, da, db;
int dis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    tot = 0;
    for (int i = 1; i <= n; i ++) head[i] = 0, dis[i] = INF;
}

int bfs(int s)
{
    dis[s] = 0;
    queue <int> q;
    q.push(s);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            if (dis[to] <= dis[now]) continue;
            dis[to] = dis[now] + 1;
            if (to == b) return dis[to];
            q.push(to);
        }
    }
}

void dfs(int now, int pre)
{
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        if (to == pre) continue;
        dis[to] = dis[now] + 1;
        dfs(to, now);
    }
}

int work()
{
    dis[1] = 0;
    dfs(1, -1);
    int mx = 0, t = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (dis[i] > mx)
        {
            mx = dis[i];
            t = i;
        }
    }
    dis[t] = 0;
    dfs(t, -1);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (dis[i] > ans) ans = dis[i];
    }
    return ans;
}

void solve()
{
    n = read(), a = read(), b = read(), da = read(), db = read();
    init();
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    int dist = bfs(a);
    if (da >= dist)
    {
        puts("Alice");
        return;
    }
    int diameter = work();
    if (da * 2 >= diameter)
    {
        puts("Alice");
        return;
    }
    if (2 * da < db)
    {
        puts("Bob");
        return;
    }
    puts("Alice");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}