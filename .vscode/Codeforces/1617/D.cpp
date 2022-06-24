#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
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
#define aa aa
#define pb emplace_back
#define xx first
#define yy second

int get(int a, int b, int c)
{
    printf("? %d %d %d\n",a,b,c);
    fflush(stdout);
    int ans;
    ans = read();
    return ans;
}
int a[MAXN];
int b[MAXN], cnt1;
int c[MAXN], cnt2;
int n;
void init()
{
    cnt1 = 0;
    cnt2 = 0;
    rep(i, 1, n+n) b[i] = 0, c[i] = 0,a[i]=0;
}

void solve()
{
    n = read();
    init();
    int err = 0;
    rep(i, 1, n)
    {
        int tmp = get(i, i + 1, i + 2);
        a[i] = tmp;
        if (i > 1 && a[i] != a[i - 1])
        {
            err = i;
            break;
        }
    }
    rep(i, 1, n)
    {
        int tmp;
        if (i != err && err + 1 != i)
        {
            tmp = get(err, err + 1, i);
            if (tmp == 0)
            {
                b[++cnt1] = i;//tmp;
            }
            else
                c[++cnt2] = i;//tmp;
        }
    }
    int tmp = get(b[1], c[1], err);
    if (tmp != 0)
        b[++cnt1] = err + 1;
    else
        b[++cnt1] = err;
    printf("! %d ",cnt1);
    fflush(stdout);
    rep(i, 1, cnt1)
    {
        printf("%d ",b[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
}

int main()
{

    int T;
    T = read();
    while (T--)
    {
        solve();
    }

    return 0;
}