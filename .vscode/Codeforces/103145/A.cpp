#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define MAXN 5000 * 5000 + 5
#define MAXM 5005
ll fac[MAXN];

ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t % mod  ;
        t = t * t % mod   ;
        k >>= 1;
    }
    return res % mod;
}

void init() {
    fac[0] = 1ll;
    for (ll i = 1; i < 5000 * 5000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

ll cnm(ll a, ll b) {
    ll invfb = quickpow(fac[b], mod - 2) % mod;
    ll invfab = quickpow(fac[a - b], mod - 2) % mod;
    return fac[a] * invfb % mod * invfab % mod;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + cnm(n * n - i, n - 1)) % mod;
    }
    ans = ans * fac[n] % mod * fac[n * n - n] % mod * n % mod;
    cout << ans % mod << endl;
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}