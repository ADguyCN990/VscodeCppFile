#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
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
ll n, k;
vector<int> g[MAXN];
int depth[MAXN];
int siz[MAXN];
void dfs(int now, int pre) {
    siz[now] = 1;
    for (int to : g[now]) {
        if (to == pre) continue;
        depth[to] = depth[now] + 1;
        dfs(to, now);
        siz[now] += siz[to];
    }
}

void solve() {
    n = read(), k = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }
    depth[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) depth[i] = siz[i] - depth[i];
    sort(depth + 1, depth + 1 + n, greater<>());
    ll ans = 0;
    for (int i = 1; i <= n - k; i++) ans += depth[i];
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}