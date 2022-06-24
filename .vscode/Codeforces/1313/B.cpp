#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    printf("%d %d\n", min(n, max(1, x + y - n + 1)), min(n, x + y - 1));
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}