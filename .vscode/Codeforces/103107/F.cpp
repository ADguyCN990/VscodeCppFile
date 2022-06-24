#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10000005

bool st[MAXN];
int p[MAXN], cnt;

ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t    ;
        t = t * t     ;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    ll ans = 1; //1的贡献筛中无法得到
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            p[++cnt] = i;
            st[i] = true;
            ans++;
        }
        for (int j = 1; p[j] <= n / i; j++) {
            int N = p[j] * i;
            st[N] = true;
            int e = 0;
            while (N % p[j] == 0) {
                e++;
                N /= p[j];
            }
            ans += quickpow(p[j], e / 2) * N; 
            if (i % p[j] == 0)
                break;
        }
    }
    printf("%lld\n", ans);
    return 0;   
}
