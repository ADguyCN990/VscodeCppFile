#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
#define INF 0x3f3f3f3f3f3f3f3f
int head[MAXN], tot;
struct EDGE {
    int to, next;
    ll val;
}edge[MAXM];
void add(int from, int to, ll val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll a[MAXN];
ll siz[MAXN], dp[MAXN], depth[MAXN];
ll n, N;

void dfs_down(int now, int pre) {
    siz[now] = a[now];
    dp[now] = depth[now] * a[now];
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (to == pre) continue;
        depth[to] = depth[now] + val;
        dfs_down(to, now);
        siz[now] += siz[to];
        dp[now] += dp[to];
    }
}

void dfs_up(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (to == pre) continue;
        dp[to] = dp[now] - siz[to] * val + (N - siz[to]) * val;
        dfs_up(to, now);
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        N += a[i];
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        ll w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dfs_down(1, -1);
    //for (int i = 1; i <= n; i++) printf("%lld\n", dp[i]);
    //puts("after:");
    dfs_up(1, -1);
    //for (int i = 1; i <= n; i++) printf("%lld\n", dp[i]);
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        //printf("%lld\n", siz[i]);
        if (dp[i] < ans) {
            ans = dp[i];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}