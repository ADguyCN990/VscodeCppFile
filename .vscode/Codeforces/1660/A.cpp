#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a, b;
    cin >> a >> b;
    if (!a) {
        puts("1");
        return;
    }
    printf("%lld\n", a + 2 * b + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}