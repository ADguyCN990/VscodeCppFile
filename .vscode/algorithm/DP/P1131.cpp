#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
#define MAXM 1000005
#define INF 0x3f3f3f3f3f3f3f3f
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, rt;
int head[MAXN], tot;
struct EDGE {
    int to, next;
    ll val;
}edge[MAXM];
void add(int from, int to, ll val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
ll depth[MAXN], mxdep;
ll dp[MAXN]; //i节点连向父亲的边的长度
ll ans = 0;
void dfs_pre(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (to == pre) continue;
        depth[to] = depth[now] + val;
        mxdep = max(mxdep, depth[to]);
        dfs_pre(to, now);
    }
}

void dfs(int now, int pre) {
    int cnt = 0; ll mn = INF;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        ll val = edge[i].val;
        if (to == pre) continue;
        dfs(to, now);
        cnt++;
        mn = min(mn, dp[to]);
    }
    if (!cnt) {
        dp[now] = mxdep - depth[now];
        ans += dp[now];
        return;
    }
    if (now != rt) {
        dp[now] = mn;
        ans -= (cnt - 1) * mn;
    }
    
}

void solve() {
    n = read(), rt = read();
    for (int i = 1; i < n; i++) {
        int u, v; ll val;
        u = read(), v = read(), val = read();
        add(u, v, val);
        add(v, u, val);
    }
    dfs_pre(rt, -1);
    dfs(rt, -1);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}