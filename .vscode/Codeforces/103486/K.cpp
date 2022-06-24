#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
#define mod 1000000007
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
ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t % mod;
        t = t * t % mod;
        k >>= 1;
    }
    return res;
}
ll fac[MAXN],inv[MAXN];
void pre() {
    fac[0] = 1;
    for (int i = 1; i <= 300000; i++) fac[i] = fac[i-1] * i % mod;
    inv[300000] = quickpow(fac[300000], mod - 2);
    for (int i = 299999; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll cnm(ll n,ll m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

ll n, k;
void solve() {
    n = read(), k = read();
    ll ans = (cnm(2 * n, n) + mod - cnm(2 * n, n - 1)) % mod;
    ans = ans * quickpow(k, n) % mod;
    printf("%lld\n", ans);
}

int main() {
    pre();
    solve();
    return 0;
}