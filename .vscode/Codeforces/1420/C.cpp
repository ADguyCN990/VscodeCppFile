#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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

ll n, q;
ll a[MAXN];

void solve()
{
    n = read(), q = read();
    rep(i, 1, n) a[i] = read();
    vector<ll> ans;
    a[n+1]=0;
    rep(i, 1, n)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            ans.emplace_back(a[i]);
        else if (a[i] < a[i - 1] && a[i] < a[i + 1] && ans.size() > 0)
            ans.emplace_back(a[i]);
    }
    ll res = 0;
    if (ans.size() % 2 == 1)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i & 1)
                res -= ans[i];
            else
                res += ans[i];
        }
    }

    else if (ans.size() % 2 == 0&&ans.size()>0)
    {
        for (int i = 0; i < ans.size() - 1; i++)
        {
            if (i & 1)
                res = ans[i];
            else
                res += ans[i];
        }
    }
    cout << res << endl;
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