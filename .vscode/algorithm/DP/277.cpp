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
ll a[55][55];
ll dp[55][55][105];
void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int k = 3; k <= n + m; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                int ax = i, ay = k - i, bx = j, by = k - j;
                if (ax < 1 || ax > n || bx < 1 || bx > n) continue;
                if (ay < 1 || ay > m || by < 1 || by > m) continue;
                ll w1 = dp[i - 1][j][k - 1], w2 = dp[i][j - 1][k - 1];
                ll w3 = dp[i][j][k - 1], w4 = dp[i - 1][j - 1][k - 1];
                ll w = max({w1, w2, w3, w4});
                dp[i][j][k] = max(dp[i][j][k], w + a[ax][ay] + a[bx][by]);
                //printf("%lld\n", dp[i][j][k]);
            }
        }
    }
    dp[n][n][n + m] = max(dp[n][n - 1][n + m - 1], dp[n - 1][n][n + m - 1]);
    printf("%lld\n", dp[n][n][n + m]);
}

int main() {
    solve();
    return 0;
}