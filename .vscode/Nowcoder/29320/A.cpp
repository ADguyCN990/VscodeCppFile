#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
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
ll n, mod;
ll a[MAXN];
ll dp[MAXN][MAXN];
void solve() {
    n = read(), mod = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++)
            dp[i][j] = dp[i - 1][j];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * a[i]) % mod;
        }
    }
    for (int i = 0; i <= n; i++)
        printf("%lld ", dp[n][i]);
}

int main() {
    solve();
    return 0;
}