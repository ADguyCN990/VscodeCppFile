#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 16005
#define MAXM 32005
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
struct EDGE {
    int to, next;
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to) {
    edge[++tot].to = to; edge[tot].next = head[from]; head[from] = tot;
}
ll a[MAXN];
ll dp[MAXN];
ll ans = -INF;
int n;

void dfs(int now, int pre) {
    ll tmp = 0;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        if (dp[to] > 0) tmp += dp[to];
    }
    dp[now] = max(0ll, a[now] + tmp);
    ans = max(ans, dp[now]);
}

void solve() {
    n = read();
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] > 0)
            flag = false;
    }
    if (flag) {
        sort(a + 1, a + 1 + n, greater<>());
        printf("%lld\n", a[1]);
        return;
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}