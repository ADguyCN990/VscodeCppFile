#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, p, q;
const int MOD = 998244353;
const int N = 500 + 1;
int f[N][N + N], g[N][N + N];
int a[N][N];

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
        x = x * 10 + (ch - '0');
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}

int main(void)
{
    n = read(), m = read(), p = read(), q = read();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = read();
        }
    }

    f[1][a[1][1]] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < i + j; ++k)
            {
                int &x = f[j][k];
                if (a[i][j])
                {
                    if (k > 0)
                    {
                        x = (x + g[j][k - 1]) % MOD;
                        x = (x + f[j - 1][k - 1]) % MOD;
                    }
                }
                else
                {
                    x = (x + g[j][k]) % MOD;
                    x = (x + f[j - 1][k]) % MOD;
                }
            }
        }
        if (i == n)
            break;
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < i + j; ++k)
            {
                g[j][k] = f[j][k];
                f[j][k] = 0;
            }
        }
    }
    ll ans = 0;
    for (int i = q; i <= n + m - 1 - p; ++i)
    {
        ans = (ans + f[m][i]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}