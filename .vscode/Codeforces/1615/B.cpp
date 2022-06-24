#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
ll sum[MAXN][35];

void pre()
{
    for (int i = 1; i <= 200000; i++)
    {
        for (int j = 0; j <= 31; j++)
        {
            int now = i >> j & 1;
            sum[i][j] = sum[i - 1][j] + now;
        }
    }
}

void solve()
{
    int l, r;
    l = read(), r = read();
    ll mn = INF;
    for (int i = 0; i <= 31; i++)
    {
        mn = min(mn, (r - l + 1) - sum[r][i] + sum[l - 1][i]);
    }
    printf("%d\n", mn);
}

int main()
{
    int T;
    T = read();
    pre();
    while (T--)
    {
        solve();
    }

    return 0;
}