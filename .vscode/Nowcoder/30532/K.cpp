#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 9982443535
ll n;


int main() {
    cin >> n;
    //n % i = (n - (n / i) * i)

    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ll len = r - l + 1;
        ll sum = (l + r) * len / 2;
        ll ans1 = n * sum % mod;
        ll ans2 = n / l * len % mod;
        ans = (ans + ans1 + mod - ans2) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}