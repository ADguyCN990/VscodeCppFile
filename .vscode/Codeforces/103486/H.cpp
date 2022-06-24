#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 200005
#define mod 998244853
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
ll inv(ll m) { //求一个数的逆元
    // a / b = a * (b ^ (mod - 2) % mod) % mod
    ll res = 1 , t = m;
    ll k = mod - 2;
    while (k) {
        if (k & 1) res = res * t % mod   ;
        t = t * t  % mod   ;
        k >>= 1;
    }
    return res;
}
map <pii, vector<int>> mp;
int a[MAXN];
int n, m, k;

void solve() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        if (u > v) swap(u, v);
        mp[{u, v}].pb(w);
    }
    ll ten = inv(10); //除以10
    ll base = 1;
    for (int i = 1; i < k - 1; i++) {
        base = base * 10 % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) a[i] = read();
    for (int i = 2; i <= k; i++) {
        int u = a[i - 1], v = a[i];
        if (u > v) swap(u, v);
        if (!mp.count({u, v})) {
            puts("Stupid Msacywy!");
            return;
        }
        pii now = {u, v};
        int len = mp[now].size();
        ll div = inv(len);

        for (int j = 0; j < mp[now].size(); j++) {
            ans = (ans + mp[now][j] * base % mod * div % mod) % mod;
        }
        base = base * ten % mod;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}