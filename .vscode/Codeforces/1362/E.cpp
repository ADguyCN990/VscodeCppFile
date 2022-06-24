#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 200005
#define mod 1000000007
#define MOD 11451449
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
ll quickpow(ll m, ll k, ll mm) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t % mm  ;
        t = t * t  % mm  ;
        k >>= 1;
    }
    return res;
}
ll n, p;
ll a[MAXN];
void solve() {
    n = read(), p = read();
    for (int i = 1; i <= n; i++) a[i] = read(); //幂次数
    sort(a + 1, a + 1 + n, greater<>());
    ll ans = 0, ANS= 0; //差值的绝对值
    for (int i = 1; i <= n; i++) {
        if (!ans && !ANS) {
            //类似于双哈希，模两个不同的模数保证值一定为0
            ans += quickpow(p, a[i], mod);
            ANS += quickpow(p, a[i], MOD);
            continue;
        }
        //否则减去一堆数，直到ans重新为0
        ans = (ans - quickpow(p, a[i], mod) + mod) % mod;
        ANS = (ANS - quickpow(p, a[i], MOD) + MOD) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}