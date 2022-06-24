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
#define MAXL 100000005
int prime[5761455 + 5];
int check[MAXL];
int sum[MAXL];
int tot = 0;

void getprime()
{
    for (int i = 2; i < MAXL; ++i)
    {
        if (!check[i])
        {
            prime[tot++] = i;
        }
        for (int j = 0; j < tot; ++j)
        {
            if (i * prime[j] > MAXL)
            {
                break;
            }
            check[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    sum[1] = 0;
    for (int i = 2; i <= 100000000; i++)
        sum[i] = sum[i - 1] + (1-check[i]);
}

void solve()
{
    ll a, b;
    a = read(), b = read();
    printf("%d\n", sum[b] - sum[a - 1]);
}

int main()
{
    getprime();
    int T;
    T = read();
    while (T--)
    {
        solve();
    }

    return 0;
}