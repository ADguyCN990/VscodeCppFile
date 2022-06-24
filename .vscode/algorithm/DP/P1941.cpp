#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 2005
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
int n, m, p;
int x[MAXN], y[MAXN];      // i位置，上升x[i],下降y[i]
int low[MAXN], high[MAXN]; // i位置能通过的范围是low[i]-high[i]
int f[MAXN][MAXM];         //到(i,j)的最少点击次数
bool e[MAXN];              // e[i]表示i位置有没有管道

void solve() {
    n = read(), m = read(), p = read();
    for (int i = 1; i <= n; i++)
        x[i] = read(), y[i] = read();
    for (int i = 1; i <= n; i++) {
        low[i] = 1;
        high[i] = m;
    }
    int a, b, c;
    for (int i = 1; i <= p; i++) {
        a = read(), b = read(), c = read();
        e[a] = 1;
        low[a] = b + 1;
        high[a] = c - 1;
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = x[i] + 1; j <= m + x[i]; ++j)
            f[i][j] = min(f[i - 1][j - x[i]] + 1, f[i][j - x[i]] + 1);
        for (int j = m + 1; j <= m + x[i]; ++j)
            f[i][m] = min(f[i][m], f[i][j]);
        for (int j = 1; j <= m - y[i]; ++j)
            f[i][j] = min(f[i][j], f[i - 1][j + y[i]]);
        for (int j = 1; j < low[i]; ++j)
            f[i][j] = f[0][0]; //不能通过(INF)
        for (int j = high[i] + 1; j <= m; ++j)
            f[i][j] = f[0][0]; //不能通过(INF)
    }
    int ans = f[0][0];
    for (int j = 1; j <= m; ++j) {
        ans = min(ans, f[n][j]);
    }
    if (ans < f[0][0])
        printf("1\n%d\n", ans);
    else {
        int i, j;
        for (i = n; i >= 1; i--) {
            for (j = 1; j <= m; ++j)  {
                if (f[i][j] < f[0][0])
                    break;
            }
            if (j <= m)
                break;
        }
        ans = 0;
        for (int j = 1; j <= i; ++j) {
            if (e[j])
                ans++;
        }
        printf("0\n%d\n", ans);
    }
}

int main() {
    solve();
    return 0;
}