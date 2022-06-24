#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 400005
#define ll long long
int head[MAXN], tot;
ll base[35];
int color[MAXN];
int n, m;
int sum0, sum1;
ll ans;
void pre()
{
    base[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        base[i] = base[i - 1] * 2;
    }
}

struct EDGE
{
    ll to, next, val;
} edge[MAXM];
void add_edge(int from, int to, ll val)
{
    edge[++tot].to = to;
    edge[tot].val = val;
    edge[tot].next = head[from];
    head[from] = tot;
}

bool dfs(int now, int k, int c)
{
    color[now] = c;
    if (!c)
        sum0++;
    else
        sum1++;
    for (int i = head[now]; i; i = edge[i].next)
    {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (val & base[k]) //第k位为1，两位染成不同
        {
            if (color[to] == -1)
            {
                if (!dfs(to, k, !c))
                    return false;
            }
            else if (color[to] == color[now])
                return false;
        }
        else if (!(val & base[k])) //第k位为0，两位染成相同
        {
            if (color[to] == -1)
            {
                if (!dfs(to, k, c))
                    return false;
            }
            else if (color[to] != color[now])
                return false;
        }
    }
    return true;
}

void solve()
{
    pre();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w), add_edge(v, u, w);
    }
    for (int j = 0; j <= 30; j++)
    {
        memset(color, -1, sizeof(color));
        
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, j, 0))
                {
                    cout << -1 << endl;
                    return;
                }
            }

            ans += base[j] * min(sum0, sum1);
            sum0 = 0, sum1 = 0;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}