#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int f[MAXN];
ll val[MAXN];
ll n, m;
ll ans = 0;
int findx(int x)
{
    if (f[x] != x)
    {
        int t = f[x];
        f[x] = findx(f[x]);
        val[x] += val[t];
    }
    return f[x];
}

void merge(int x, int y, ll temp) //x<y
{
    int fx = findx(x); //类似于前缀和，要减去1
    int fy = findx(y);
    if (fx == fy) //判断有没有矛盾
    {
        if (val[x] + temp != val[y])
        {
            ans++;
            return;
        }
    }
    else if (fx < fy)
    {
        f[fy] = fx;
        val[fy] = val[x] + temp - val[y];
    }
    else if (fy < fx)
    {
        f[fx] = fy;
        val[fx] = val[y] - temp - val[x];
    }
    int valfx, valfy;
    valfx = val[fx];
    valfy = val[fy];
}

void solve()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
            f[i] = i;
        for (int i = 0; i <= n; i++)
            val[i] = 0;
        ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            ll temp;
            cin >> u >> v >> temp;
            merge(u - 1, v, temp);
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}