#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 500005
ll fac[N], invf[N];
ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t % mod   ;
        t = t * t % mod    ;
        k >>= 1;
    }
    return res % mod;
}

void init() {
    fac[0] = invf[0] = 1ll;
    for (ll i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invf[i] = invf[i - 1] * quickpow(i, mod - 2) % mod;
    }
}

ll div(ll x) {
    return quickpow(x, mod - 2) % mod;
}

ll cnm(ll a, ll b) {
    return fac[a] * invf[b] % mod * invf[a - b] % mod;
}

void solve() {
    ll n, m, k, q;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
    //n个黑球m个白球取出k个球连续q次都为黑球的概率
    ll a = cnm(n, k);
    ll b = cnm(n + m, k);
    ll c = a * div(b) % mod;
    ll ans = quickpow(c, q) % mod;
    printf("%lld\n", ans);
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}