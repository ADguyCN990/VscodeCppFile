#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 155
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
ll dp[MAXN];
void solve() {
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans1 = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                mx = max(mx, dp[j]);
        dp[i] = mx + 1;
    }
    for (int i = 1; i <= n; i++) ans1 = max(ans1, dp[i]);
    memset(dp, 0, sizeof dp);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j < i; j++)
            if (a[j] > a[i])
                mx = max(mx, dp[j]);
        dp[i] = mx + 1;
    }
    ll ans2 = 0;
    for (int i = 1; i <= n; i++) ans2 = max(ans2, dp[i]);
    printf("%lld\n", min(ans1, ans2));
}

int main() {
    while (1) {
        n = read();
        if (!n) break;
    }
    return 0;
}