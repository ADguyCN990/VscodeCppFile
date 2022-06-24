#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define MAXM 2000005
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
ll siz[MAXN], dp[MAXN], depth[MAXN];
int n;

void dfs_down(int now, int pre) {
    siz[now] = 1;
    dp[now] = depth[now];
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        depth[to] = depth[now] + 1;
        dfs_down(to, now);
        siz[now] += siz[to];
        dp[now] += dp[to];
    }
}

void dfs_up(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dp[to] = dp[now] - siz[to] + n - siz[to];
        dfs_up(to, now);
    }
}

void solve() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs_down(1, -1);
    dfs_up(1, -1);
    ll ans = 0, id = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            id = i;
        }
    }
    printf("%d\n", id);
}

int main() {
    solve();
    return 0;
}
