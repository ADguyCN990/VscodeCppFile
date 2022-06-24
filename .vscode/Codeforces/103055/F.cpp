#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, m;
    cin >> n >> m;
    //使m是n的倍数，要么使m自增1，要么使n自减1
    if (m % n == 0) {
        puts("0");
        return;
    }
    if (m < n) {
        printf("%lld\n", n - m);
        return;
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = (m - 1) / ((m - 1) / l);
        ans = min(ans, n - m + ((m - 1) / l) * l);
    }

    printf("%lld\n", ans);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}