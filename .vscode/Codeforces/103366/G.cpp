#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 50005
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
#define N 50000
vector<int> fac[MAXN];
bool vis[MAXN];
int n, m;
int a[MAXN];
int cnt[MAXM], num[MAXM], ans[MAXM];
int mx;
void pre() // 预处理每个数的质因子
{
    for (int i = 2; i <= 1e6; i++)
    {
        if (!vis[i])
        {
            for (int j = i; j <= 1e6; j += i)
            {
                vis[j] = true;
                fac[j].pb(i);
            }
        }
    }
}

int get(int x)
{
    return x / sqrt(N);
}

struct node
{
    int l, r, id;
    bool operator<(const node &now) const
    {
        if (get(l) != get(now.l))
            return l < now.l;
        if (get(l) & 1)
            return r > now.r;
        return r < now.r;
    }
} q[MAXM];

void del(int x)
{
    for (auto p : fac[a[x]])
    {
        num[cnt[p]]--;
        if (mx == cnt[p] && num[cnt[p]] == 0)
            mx--;
        cnt[p]--;
        num[cnt[p]]++;
    }
}

void add(int x)
{
    for (auto p : fac[a[x]])
    {
        num[cnt[p]]--;
        cnt[p]++;
        num[cnt[p]]++;
        mx = max(mx, cnt[p]);
    }
}

void solve()
{
    n = read(), m = read();
    mx = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= m; i++)
    {
        q[i].l = read(), q[i].r = read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i)
    {
        while (l < q[i].l)
            del(l ++);
        while (l > q[i].l)
            add(-- l);
        while (r < q[i].r)
            add(++ r);
        while (r > q[i].r)
            del(r --);
        ans[q[i].id] = mx;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    while (l <= r) //清空
        del(l ++);
}

int main()
{
    pre();
    int T;
    T = read();
    while (T--)
    {
        solve();
    }
    return 0;
}