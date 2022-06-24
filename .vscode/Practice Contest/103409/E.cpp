#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define MAXM 5005
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
typedef pair<ll, int> pii;

struct EDGE {
    int to, next, val;
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to, int val) {
    edge[++tot].to = to;
    edge[tot].val = val;
    edge[tot].next = head[from];
    head[from] = tot;
}
int n, m, c;
ll dis[MAXN];
int vis[MAXN];

int dij(int s) {
    for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({dis[s], s});
    while (q.size()) {
        int now = q.top().second;
        q.pop();
        if (vis[now]) continue;
        vis[now] = 1;
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (to == s && dis[now] + val <= c) return 1;
            if (dis[to] > dis[now] + val) {
                dis[to] = dis[now] + val;
                q.push({dis[to], to});
            }
        }
    }
    return 0;
}

void solve() {
    scanf("%d%d%d", &n, &m, &c);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w <= c && !ans) ans++;
        add(u, v, w);
    }
    for (int i = 1; i <= n; i++) {
        int tmp = dij(i);
        if (tmp == 1) {
            ans++;
            break;
        }
    }
    printf("%d\n", ans);
}


int main() {
    solve();
    return 0;
}