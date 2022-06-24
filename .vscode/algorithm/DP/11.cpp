#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, V;
ll v[MAXN], w[MAXN];
ll mx;
ll dp[MAXN];
ll cnt[MAXN];
void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) v[i] = read(), w[i] = read();  
    cnt[0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            ll tmp = max(dp[j], dp[j - v[i]] + w[i]);
            ll now = 0;
            if (tmp == dp[j - v[i]] + w[i])
                now = (now + cnt[j - v[i]]) % mod;
            if (tmp == dp[j])
                now = (now + cnt[j]) % mod;
            dp[j] = tmp, cnt[j] = now;
        }
    } 
    ll ans = 0;
    for (int i = 0; i <= V; i++) 
        if (dp[i] == dp[V])
            ans = (ans + cnt[i]) % mod;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}