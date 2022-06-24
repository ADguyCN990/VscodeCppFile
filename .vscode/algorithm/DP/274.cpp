#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
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
ll n;
ll a[MAXN];
ll b[MAXN];
ll dp[MAXN][MAXN]; //a前i个，b前j个，且以bj为结尾的最长上升公共子序列
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (a[i] == b[j]) dp[i][j] = max(mx + 1, dp[i][j]);
            if (b[j] < a[i]) mx = max(mx, dp[i - 1][j]);
                // for (int k = 1; k < j; k++) 
                //     if (b[j] > b[k])
                //         dp[i][j] = max(dp[i - 1][k] + 1, dp[i][j]);         
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}