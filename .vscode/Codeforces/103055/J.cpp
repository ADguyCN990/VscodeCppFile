#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
#define MAXM 6005
#define INF 0x3f3f3f3f
int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
int n, m, V;
ll a[MAXN];
ll dp[MAXN][MAXN];
int dis[MAXN];

void bfs(int s) {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            if (dis[to] != -1) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
        }
    }
}

void solve() {
    cin >> n >> m >> V;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) dis[i] = dis[i] * 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= dis[i])
                dp[i][j] = max(dp[i][j], dp[i][j - dis[i]] + a[i]);
        }
    }
    for (int i = 1; i <= V; i++) printf("%lld ", dp[n][i]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        solve();
    return 0;
}