#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 205
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
ll n, m;
struct EDGE {
    int to, next, val;
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
ll dp[MAXN][MAXN];

void dfs(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) continue;
        dfs(to, now);
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < j; k++) {
                dp[now][j] = max(dp[now][j - k - 1] + dp[to][k] + val, dp[now][j]);
            }
        }
        
    }
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1);
    printf("%lld\n", dp[1][m]);
}

int main() {
    solve();
    return 0;
}