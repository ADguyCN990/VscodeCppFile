#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int head[MAXN];int tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add_edge(int from,int to) {
    edge[++tot].to = to; edge[tot].next = head[from]; head[from] = tot;
}
ll a[MAXN], b[MAXN], c[MAXN];
int one[MAXN], zero[MAXN];
int n, m;
ll ans = 0;
void dfs(int now, int pre, ll cost) {
    cost = min(cost, a[now]); //子树中最小花费的点
    if (b[now] != c[now]) {
        if (b[now] == 1)
            one[now]++;
        else 
            zero[now]++;
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now, cost);
        one[now] += one[to];
        zero[now] += zero[to];
    }
    if (cost == a[now]) {
        int cnt = min(one[now], zero[now]);
        ans += 2 * cnt * a[now];
        one[now] -= cnt;
        zero[now] -= cnt;
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        b[i] = read();
        c[i] = read();
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0, INF);
    if (one[1] || zero[1]) {
        puts("-1");
    }
    else {
        printf("%lld\n", ans);
    }
}

int main() {
    solve();
    return 0;
}