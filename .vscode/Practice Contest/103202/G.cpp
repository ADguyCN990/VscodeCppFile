#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll n, k;
ll a[MAXN];
ll sum = 0;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<>());
    for (int i = 1; i <= k; i++) sum += a[i];

    cout << sum << endl;
}