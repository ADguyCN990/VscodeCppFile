#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define MAXM 50005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
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
int n, m, q;
ll t[MAXN];
ll dis[MAXN][MAXN];
ll ans[MAXN];
struct node
{
    int u, v, tim, id;
}a[MAXM];
bool cmp(node a, node b) {return a.tim < b.tim;}
void init()
{
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            i == j ? dis[i][j] = 0 : dis[i][j] = LLINF;
}

void update(int k)
{
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void solve()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i ++) t[i] = read();
    init();
    for (int i = 1; i <= m; i ++)
    {
        ll u, v, w;
        u = read(), v = read(), w = read();
        dis[u + 1][v + 1] = min(dis[u + 1][v + 1], w);
        dis[v + 1][u + 1] = min(dis[v + 1][u + 1], w);
    }
    for (int i = 1; i <= q; i ++)
    {
        a[i].u = read() + 1, a[i].v = read() + 1, a[i].tim = read();
        a[i].id = i;
    }
    sort (a + 1, a + 1 + q, cmp);
    int now = 1;
    for (int i = 1; i <= q; i ++)
    {
        while (t[now] <= a[i].tim && now <= n) update(now ++);
        if (t[a[i].u] > a[i].tim || t[a[i].v] > a[i].tim)
        {
            ans[a[i].id] = -1;
            continue;
        }
        if (dis[a[i].u][a[i].v] == LLINF) ans[a[i].id] = -1;
        else ans[a[i].id] = dis[a[i].u][a[i].v];
    }
    for (int i = 1; i <= q; i ++) printf("%lld\n", ans[i]);
}

int main()
{
    solve();
    return 0;
}