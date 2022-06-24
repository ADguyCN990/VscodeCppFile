#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n, m, V;
ll v[MAXN][MAXN];
ll dp[MAXM]; //前i天，第j个物品，第二天卖掉的钱
void solve() {
    n = read(), m = read(), V = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            v[i][j] = read();
    for (int i = 1; i < n; i++) {
        memset(dp, -0x3f, sizeof dp);
        dp[V] = V;
        for (int k = 1; k <= m; k++) {
            for (int j = V; j >= v[i][k]; j--) {
                dp[j - v[i][k]] = max(dp[j - v[i][k]], dp[j] - v[i][k] + v[i + 1][k]);
            }
        }
        ll ans = -INF;
        for (int j = 0; j <= V; j++)
            ans = max(ans, dp[j]);
        V = ans;
        //printf("V: %lld\n", V);
    }
    printf("%lld\n", V);
}

int main() {
    solve();
    return 0;
}