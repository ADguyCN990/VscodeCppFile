#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n, x, y, dp[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

void dfs(int now, int pre) {
    bool f = false;
    dp[now] = -1;
    for (auto to : g[now]) {
        if (to == pre) continue;
        dfs(to, now);
        if (vis[to])
            f = true;
        dp[now] += max(dp[to], (vis[to] ? 1 : 0));
    }
    if (!f || dp[now] > 0)
        vis[now] = true;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, -1);
    if (dp[1])
        puts("Alice");
    else
        puts("Bob");
    return 0;
}