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
ll b[MAXN], m;
ll dp[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans = 0;
    for (int i = 1; i <= n; i += 2) ans += a[i];
    m = 0;
    for (int i = 2; i <= n; i += 2) {
        b[++m] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        dp[i] = max(dp[i - 1], 0ll) + b[i];
    }
    ll tmp = 0;
    for (int i = 1; i <= m; i++) {
        tmp = max(tmp, dp[i]);
    }
    //printf("tmp: %lld\n", tmp);
    m = 0;
    for (int i = 3; i <= n; i += 2) {
        b[++m] = a[i - 1] - a[i];
    }
    for (int i = 1; i <= m; i++) {
        dp[i] = max(dp[i - 1], 0ll) + b[i];
    }
    for (int i = 1; i <= m; i++) {
        tmp = max(tmp, dp[i]);
    }
    //printf("tmp: %lld\n", tmp);
    printf("%lld\n", ans + tmp);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}