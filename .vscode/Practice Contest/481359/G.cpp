#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll, ll> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define per(i, x, y) for(ll i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll bsgs(ll a, ll b, ll p) {
    if (1 % p == b % p) return 0;
    ll k = sqrt(p) + 1;
    unordered_map<ll, ll> mp;
    for (ll i = 0, j = b % p; i < k; i ++) {
        mp[j] = i;
        j = j * a % p;
    }
    ll ak = 1;
    for (ll i = 0; i < k; i ++) ak = ak * a % p;
    for (ll i = 1, j = ak; i <= k; i ++) {
        if (mp.count(j)) return i * k - mp[j];
        j = j * ak % p;
    }
    return -1;
}

void solve() {
    ll a = read(), b = read(), p = read();
    ll x = bsgs(a, b, p);
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