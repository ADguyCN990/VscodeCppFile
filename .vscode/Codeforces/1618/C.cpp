#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
#define debug(x) cout << "!!!" << x << endl
#define pb emplace_back
#define xx first
#define yy second
ll quickpow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            n--;
            ans = (ans * a);
        }
        else if (n % 2 == 0)
        {
            n /= 2;
            a = (a * a);
        }
    }
    return ans;
}
const int N = 1000000;
int prime[N + 5];
void getprime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= N; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= N / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll factor[1005][2];
int fatcnt;
int getfactors(ll x)
{
    fatcnt = 0;
    ll tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatcnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatcnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatcnt][1]++;
                tmp /= prime[i];
            }
            fatcnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatcnt][0] = tmp;
        factor[fatcnt++][1] = 1;
    }
    return fatcnt;
}
int head[MAXN];
int tot;
struct EDGE
{
    int to, next, val;
} edge[MAXM];
void add_edge(int from, int to, int val)
{
    edge[++tot].to = to;
    edge[tot].val = val;
    edge[tot].next = head[from];
    head[from] = tot;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll tmp;
    while (b)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
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
int f[MAXN];
int findx(int x)
{
    if (x == f[x])
        return x;
    else
        return f[x] = findx(f[x]);
}
void merge(int x, int y)
{
    int fx = findx(x);
    int fy = findx(y);
    if (fy != fx)
        f[fy] = fx;
}
ll n;
ll a[MAXN];
void solve()
{
    n = read();
    rep(i, 1, n) a[i] = read();
    int f1 = 0, f2 = 0;
    ll g1 = a[1], g2 = a[2];
    //求奇数位和偶数位上的gcd
    rep(i, 3, n)
    {
        if (i % 2)
            g1 = gcd(g1, a[i]);
        else
            g2 = gcd(g2, a[i]);
    }
    if (g1 == 1)
        f2 = 1;
    if (g2 == 1)
        f1 = 1;
    //check一下偶数位上的数能否被奇数位上的gcd整除，奇数位上的数能否被偶数位上的gcd整除
    if (g2 > 1)
    {
        for (int i = 1; i <= n; i += 2) //奇数模g2
        {
            if (a[i] % g2 == 0)
            {
                f1 = 1;
                break;
            }
        }
    }
    if (g1 > 1)
    {
        for (int i = 2; i <= n; i += 2) //偶数模g1
        {
            if (a[i] % g1 == 0)
            {
                f2 = 1;
                break;
            }
        }
    }
    //判断
    if (f1 == 0)
    {
        cout << g2 << endl;
        return;
    }
    else if (f2 == 0)
    {
        cout << g1 << endl;
        return;
    }
    else if (f1 && f2)
    {
        cout << 0 << endl;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    T = read();
    while (T--)
    {
        solve();
    }

    return 0;
}