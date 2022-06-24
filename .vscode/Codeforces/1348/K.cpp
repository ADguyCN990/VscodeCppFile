#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mAXn 200005
#define mAXm 200005
typedef pair<ll, ll> pii;
#define InF 0x3f3f3f3f
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define per(i, x, y) for(ll i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
unordered_map<ll, int> h;
ll n, m, p;
ll gcd(ll a, ll b){
    if (!b) return a ;
    return gcd(b, a % b) ;
}

ll expow(ll a, ll b, ll mod){
    ll res = 1 ;
    while (b) res = ((b & 1)?res * a % mod : res), a = a * a % mod, b >>= 1 ;
    return res ;
}

ll exgcd(ll &x, ll &y, ll a, ll b){
    if (!b){ x = 1, y = 0 ; return a ; }
 	ll t = exgcd(y, x, b, a % b) ; y -= x * (a / b) ; return t ;
}

ll BSGS(ll a, ll b, ll mod, ll qaq){
    h.clear() ; ll Q, p = ceil(sqrt(mod)), x, y ; 
    exgcd(x, y, qaq, mod), b = (b * x % mod + mod) % mod, 
    Q = expow(a, p, mod), exgcd(x, y, Q, mod), Q = (x % mod + mod) % mod ;
    for (ll i = 1, j = 0 ; j <= p ; ++ j, i = i * a % mod)  if (!h.count(i)) h[i] = j ;
    for (ll i = b, j = 0 ; j <= p ; ++ j, i = i * Q % mod)  if (h[i]) return j * p + h[i] ; return -1 ;
}

ll exBSGS(){
    ll qaq = 1 ;
    ll k = 0, qwq = 1 ; 
    if (m == 1) return 0 ; 
    while ((qwq = gcd(n, p)) > 1){
        if (m % qwq) return -1 ;
        ++ k, m /= qwq, p /= qwq, qaq = qaq * (n / qwq) % p ;
        if (qaq == m) return k ;
    }
    return (qwq = BSGS(n, m, p, qaq)) == -1 ? -1 : qwq + k ;
}

void solve() {
    h.clear();
    n = read(), m = read(), p = read();
    ll x = exBSGS();
    printf("%lld\n", x);
}

int main() {
    ll T;
    T = read();
    for (ll i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}