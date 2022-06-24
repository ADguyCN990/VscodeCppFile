#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll quickpow(ll m, ll k, ll mod) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t  %mod  ;
        t = t * t   %mod  ;
        k >>= 1;
    }
    return res;
}    
int main() {
    ll n;
    cin >> n;
    cout << quickpow(n, n, n + 2);
    return 0;
}