#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    cout << 6 * n << " " << 3 << endl;
    cout << n << " " << 2 * n << " " << 3 * n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}