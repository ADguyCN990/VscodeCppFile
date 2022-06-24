#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define MAXN 200005
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXN];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}

int n, m;

void init() {
    tot = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
}

ll dp[MAXN][5]; 
//0表示删除
//1表示被父亲
//2表示被儿子

void dfs(int now, int pre) {
    dp[now][0] = 1, dp[now][1] = 1, dp[now][2] = 1;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        dp[now][0] = (dp[now][0] * (dp[to][0] + dp[to][2]) % mod) % mod;
        dp[now][1] = dp[now][1] * dp[to][0] % mod;
        dp[now][2] = (dp[now][2] * (dp[to][0] + dp[to][1] + dp[to][2]) % mod) % mod;
    }
    dp[now][2] = (dp[now][2] + mod - dp[now][1]) % mod;
}

void solve() {
    n = read();
    init();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
    printf("%lld\n", (dp[1][0] + dp[1][2]) % mod);
}

int main() {
    int t;
    t = read();
    while (t--)
        solve();
    return 0;
}