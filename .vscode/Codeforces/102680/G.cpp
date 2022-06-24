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
ll dis[505][505];
void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
}

void solve() {
    n = read(), m = read();
    init();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        dis[u][v] = 1;
        dis[v][u] = 1;
    }
    ll ans = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, dis[i][j]);
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