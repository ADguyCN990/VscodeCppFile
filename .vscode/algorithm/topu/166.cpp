#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define pb emplace_back
ll read()
{
    ll x = 0, f = 1;
    char ch;
    do
    {
        ch = getchar();
        if (ch == '-')
            f = -1;
    } while (ch < '0' || ch > '9');
    do
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}

int head[MAXN];
int tot;
struct EDGE
{
    int to, next;
} edge[MAXM];
void add_edge(int from, int to)
{
    edge[++tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot;
}

int n, m;
int indgr[MAXN], a[MAXN], cnt; //求出来的拓扑序
bitset<MAXN> f[MAXN];

void topu()
{
    queue<int> q;
    rep(i, 1, n)
    {
        if (!indgr[i])
            a[++cnt] = i, q.push(i);
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next)
        {
            int to = edge[i].to;
            if (--indgr[to] == 0)
                a[++cnt] = to, q.push(to);
        }
    }
}

void solve()
{
    n = read(), m = read();
    rep(i, 1, m)
    {
        int u, v;
        u = read(), v = read();
        add_edge(u, v);
        indgr[v]++;
    }

    topu();

    for (int i = n; i; i--)
    {
        int now = a[i];
        f[now][now] = 1;
        for (int j = head[now]; j; j = edge[j].next)
        {
            int to = edge[j].to;
            f[now] |= f[to];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = f[i].count();
        printf("%d\n", ans);
    }
}

int main()
{
    solve();
    return 0;
}