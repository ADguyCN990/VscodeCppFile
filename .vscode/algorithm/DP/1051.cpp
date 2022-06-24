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
ll n;
ll a[MAXN];
ll dp[2][MAXN]; //1表示抢劫i，0表示不抢劫i
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dp[0][0] = 0; dp[1][0] = 0;
    dp[0][1] = 0, dp[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = max(dp[0][i - 1] + a[i], dp[1][i - 2] + a[i]);
    }
    printf("%lld\n", max(dp[0][n], dp[1][n]));
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}