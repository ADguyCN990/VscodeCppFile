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
ll n, m;
vector<pii> g[MAXN];
double dp[MAXN]; //以i作为起点，到达各个终点的路径期望之和

double dfs(int now) {
    if (dp[now] >= 0) {
        //已经搜索过了
        return dp[now];
    }
    int len = g[now].size();
    dp[now] = 0.0;
    for (int i = 0; i < len; i++) {
        int to = g[now][i].first;
        double val = g[now][i].second + 0.0;
        dp[now] += (val + dfs(to)) / (len + 0.0);
    }
    return dp[now];
}

void solve() {
    n = read(), m = read();
    memset(dp, ~0x3f, sizeof dp);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        u = read(), v = read(), w = read();
        g[u].pb(v, w);
    }
    dfs(1);
    printf("%.2lf\n", dp[1]);
}

int main() {
    solve();
    return 0;
}