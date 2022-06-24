#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1505
#define MAXM 3005
#define INF 0x3f3f3f3f3f3f3f3f
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
struct EDGE {
    int to, next;
}edge[MAXM];
int head[MAXM], tot;
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
int n;
ll a[MAXN];
ll dp[3][MAXN];
//0表示被父亲观察，1表示被自己观察，2表示被儿子观察
//0的话儿子要么被自己观察，要么被自己的儿子观察
//1的话儿子被自己，父亲，儿子观察
//2的话儿子被自己观察的状态中找一种最小的方案，其余的儿子和0同理

void dfs(int now, int pre) {
    dp[0][now] = 0, dp[1][now] = a[now], dp[2][now] = INF;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        dp[0][now] += min(dp[1][to], dp[2][to]);
        dp[1][now] += min({dp[0][to], dp[1][to], dp[2][to]});
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dp[2][now] = min(dp[2][now], dp[0][now] - min(dp[1][to], dp[2][to]) + dp[1][to]);
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int k, u;
        u = read(), a[u] = read(), k = read();
        while (k--) {
            int v = read();
            add(u, v);
            add(v, u);
        }
    }
    dfs(1, -1);
    printf("%lld\n", min(dp[1][1], dp[2][1]));
}

int main() {
    solve();
    return 0;
}