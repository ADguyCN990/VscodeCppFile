#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define INF 0x3f3f3f3f
ll read() {
    ll x = 0, f = 1;char ch;
    do {ch = getchar();if (ch == '-')f = -1;} while (ch < '0' || ch > '9');
    do { x = x * 10 + ch - 48;ch = getchar();} while (ch >= '0' && ch <= '9');
    return x * f;
}
int n;
int p[MAXN], c[MAXN];
bool vis[MAXN];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    for (int i = 1; i <= n; i++)
        p[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector<int> cycle;
        int now = i;
        while (cycle.empty() || now != i) {
            cycle.push_back(now);
            vis[now] = true;
            now = p[now];
        }
        int m = cycle.size();
        for (int len = 1; len <= m; len++) { //新环边的长度为len
            if (m % len) continue;
            for (int cur = 0; cur < len; cur++) {
                int color = c[cycle[cur]];
                bool flag = true;
                for (int to = cur; to < m; to += len) {
                    if (c[cycle[to]] != color) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = min(ans, len);
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t = read();
    while (t--)
        solve();
}