#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
int n;
int a[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    vector<int> num;
    num.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        num.push_back(a[i] - a[i - 1]);
    }
    sort(num.begin(), num.end());
    int ans = a[0];
    for (int i = 0; i < num.size(); i++) {
        ans = ans + (n - i) * num[i];
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}