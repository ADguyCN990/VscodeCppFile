#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXM 400005
#define INF 0x3f3f3f3f
int n, m;
int a[MAXN];
int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
int dis[MAXN], cnt[MAXN];

void multibfs() {
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        dis[a[i]] = 0;
        cnt[a[i]] = 1;
        q.push(a[i]);
    }

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            if (dis[to] == dis[now] + 1)
                cnt[to] += cnt[now];
            if (dis[to] > dis[now] + 1) {
                dis[to] = dis[now] + 1;
                cnt[to] = cnt[now];
                q.push(to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    multibfs();
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == m) {
            puts("YES");
            printf("%d\n", i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}