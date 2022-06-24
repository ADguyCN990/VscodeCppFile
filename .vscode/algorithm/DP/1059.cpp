#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
ll n, k;
ll a[MAXN];
ll dp[2][2][105]; //前i天，交易k次，状态为 0（空仓）1（持仓）
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(dp, ~0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int pre = 1 - now;
        for (int j = 0; j <= k; j++) {
            //若持仓，要么前一天也持仓，要么当前这一天买入股票
            dp[now][1][j] = max(dp[pre][1][j], dp[pre][0][j] - a[i]);
            //若空仓，要么前一天也空仓，要么当前这一天卖出股票
            if (!j) 
                dp[now][0][j] = 0;
            else
                dp[now][0][j] = max(dp[pre][0][j], dp[pre][1][j - 1] + a[i]);
        }
    }
    ll ans = -INF;
    for (int i = 0; i <= k; i++) ans = max(ans, dp[i & 1][0][i]);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}