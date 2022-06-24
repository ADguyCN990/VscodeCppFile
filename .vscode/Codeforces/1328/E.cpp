#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int depth[MAXN], n, m;
int head[MAXN], tot;
int a[MAXN];
int f[MAXN][35];
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}

void dfs(int now, int pre) {
    depth[now] = depth[pre] + 1;
    for (int i = 0; i <= 25; i++) {
        f[now][i + 1] = f[f[now][i]][i];
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        f[to][0] = now;
        dfs(to, now);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = 25; i >= 0; i--) {
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
        if (x == y)
            return x;
    }
    for (int i = 25; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int get(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

void work() {
    int k = read();
    for (int i = 1; i <= k; i++) a[i] = read();
    pii mx = {-1, 0};
    for (int i = 1; i <= k; i++) {
        if (depth[a[i]] > mx.first) {
            mx.first = depth[a[i]];
            mx.second = a[i];
        }
    }
    for (int i = 1; i <= k; i++) {
        if (get(lca(mx.second, a[i]), a[i]) > 1) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    while (m--) {
        work();
    }
}

int main() {
    solve();
    return 0;
}