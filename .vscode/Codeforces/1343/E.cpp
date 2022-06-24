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
ll n, m, a, b, c;
ll w[MAXN];
vector<int> g[MAXN];
int disa[MAXN], disb[MAXN], disc[MAXN];
ll sum[MAXN];
void init() {
    for (int i = 1; i <= n; i++)
        g[i].clear(), disa[i] = 0, disb[i] = 0, disc[i] = 0;
}

void bfs(int s, int dis[]) {
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int now = q.front();
        q.pop();
        for (int to : g[now]) {
            if (dis[to]) continue;
            if (to == s) continue;
            dis[to] = dis[now] + 1;
            q.push(to);
        }
    }
}

void solve() {
    n = read(), m = read(), a = read(), b = read(), c = read();
    init();
    for (int i = 1; i <= m; i++)
        w[i] = read();
    sort(w + 1, w + 1 + m);
    for (int i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + w[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }
    bfs(a, disa);
    bfs(b, disb);
    bfs(c, disc);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        if (disa[i] + disb[i] + disc[i] > m)
            continue;
        //printf("disa: %lld disb: %lld disc: %lld\n", disa[i], disb[i], disc[i]);
        ans = min(ans, sum[disb[i]] + sum[disa[i] + disb[i] + disc[i]]);
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}