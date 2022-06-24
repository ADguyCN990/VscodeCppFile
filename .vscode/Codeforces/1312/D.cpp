#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define MAXN 200005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll n, m;
ll fac[MAXN], invf[MAXN];

ll qmi(ll a, ll b, ll p) {
    ll res = 1ll % p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = invf[0] = 1ll;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % mod;
        invf[i] = invf[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main() {
    n = read(), m = read();
    if (n == 2) {
        puts("0");
        return 0;
    }
    init();
    //m个数中选(m-n+1)个数作为最大值
    //一共n-1个数，去掉最大值就是n-2个数，其中选择一个数作为特殊组
    //剩下的n-3个数每个数都可以选择在左边或者右边
    //ans = C_{m}^{m - n + 1} * (n - 2) * 2 ^ {n - 3}
    ll ans = fac[m] * invf[m - n + 1] % mod * invf[n - 1] % mod;
    ans = ans * (n - 2) % mod * qmi(2, n - 3, mod) % mod;
    printf("%lld\n", ans);
    return 0;
}