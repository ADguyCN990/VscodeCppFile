#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10
int n;
int a[MAXN];

void solve() {
    cin >> n;
    a[1] = 7, a[2] = 27, a[3] = 41, a[4] = 49, a[5] = 63, a[6] = 78, a[7] = 108;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += a[x];
    }
    if (ans >= 120)
        ans -= 50;
    else if (ans >= 89)
        ans -= 30;
    else if (ans >= 69)
        ans -= 15;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}