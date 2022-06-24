#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005

int n, k;
struct EDGE {
    int to, next, val;
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
bool key[MAXN];
int siz[MAXN];
int ans = 0;

void dfs_pre(int now, int pre) {
    if (key[now]) siz[now] = 1;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs_pre(to, now);
        siz[now] += siz[to];
    }
}

void dfs(int now, int pre) {
    if (!siz[now]) return;
    ans++;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        if (!key[now] && siz[to] == k) ans--;
        dfs(to, now);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        key[x] = true;
    }
    dfs_pre(1, -1);
    dfs(1, -1);
    printf("%d\n", ans);
    return 0;
}