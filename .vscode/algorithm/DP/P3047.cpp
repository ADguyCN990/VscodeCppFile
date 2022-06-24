#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
ll read() {
    ll x=0,f=1;char ch;
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
ll n, k;
ll a[MAXN];
ll dp[MAXN][25];
ll down[MAXN][25];

void dfs_down(int now, int pre) {
    for (int i = 0; i <= k; i++) down[now][i] = a[now];
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs_down(to, now);
        for (int j = 1; j <= k; j++)
            down[now][j] += down[to][j - 1];
    }
}

void dfs_up(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dp[to][1] += down[now][0];
        for (int j = 2; j <= k; j++)
            dp[to][j] += dp[now][j - 1] - down[to][j - 2]; 
        //此时now以完成更新，用父亲来更新儿子 
        dfs_up(to, now);
    }
}

void solve() {
    n = read(), k = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) a[i] = read();
    dfs_down(1, -1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = down[i][j];
    dfs_up(1, -1);
    for (int i = 1; i <= n; i++)
        printf("%lld\n", dp[i][k]);
}

int main() {
    solve();
    return 0;
}