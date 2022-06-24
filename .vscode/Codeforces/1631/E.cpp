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
int n;
int a[MAXN], r[MAXN], opt[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        opt[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (opt[a[i]])
        {
            r[i] = opt[a[i]];
            opt[a[i]] = 0;
        }
    }
    int ans = 0, pos = 0, curr = 0;
    for (int i = 1; i <= n; i = max(i + 1, curr + 1))
    {
        if (r[i] == i || r[i] == 0)
            continue;
        ans += r[i] - i - 1;
        curr = r[i];
        while (1)
        {
            pos = max(pos, i + 1);
            int optpos = 0, rmx = curr;
            while (pos <= curr)
            {
                if (r[pos])
                {
                    if (rmx < r[pos])
                        rmx = r[pos], optpos = pos;
                }
                pos++;
            }
            if (rmx - r[i] <= 1)
                rmx = 0, optpos = 0;
            if (optpos)
            {
                ans += rmx - curr - 1;
                curr = rmx;
            }
            else
                break;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}