#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
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
ll multi[MAXN];
ll dp[MAXN][MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        a[i + n] = a[i];
    }
    ll N = 2 * n;
    multi[0] = 1;
    memset(dp, ~0x3f, sizeof dp);
    for (int len = 2; len <= n + 1; len++) {
        for (int l = 1, r; r = l + len - 1, r <= N; l++) {
            if (len == 2) {
                dp[l][r] = 0;
            }
            else {
                for (int k = l + 1; k < r; k++) {
                    //[l,k][k,r]
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[r] * a[k]);
                }
            }
        }
    }
    ll ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i + n]);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}