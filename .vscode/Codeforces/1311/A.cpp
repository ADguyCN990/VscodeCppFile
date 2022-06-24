#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        puts("0");
        return;
    }
    //奇数，加
    if (b < a) {
        int dx = a - b;
        if (dx & 1)
            puts("2");
        else
            puts("1");
    }
    else {
        int dx = b - a;
        if (dx & 1)
            puts("1");
        else
            puts("2");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}