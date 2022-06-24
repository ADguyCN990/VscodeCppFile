#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll quickpow(ll m, ll k, ll mod) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t  % mod  ;
        t = t * t % mod    ;
        k >>= 1;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> num;
    while (n) {
        num.push_back(n % 2);
        //printf("%d", n % 2);
        n /= 2;
    }
    //puts("");
    ll ans = 0;
    for (int i = 0; i < num.size(); i++) 
        if (num[i])
            ans += quickpow(k, i, 100000007);
    cout << ans << endl;
    return 0;
}