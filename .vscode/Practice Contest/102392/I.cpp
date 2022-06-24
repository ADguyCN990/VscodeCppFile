#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll a[MAXN], b[MAXN];
ll ans = 0;

int main() {
    int n;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        ll dx = 0x3f3f3f3f3f3f3f3f;
        for (int j = 1; j <= n; j++) dx = min(dx, abs(a[i] - b[j]));
        ans = max(ans, dx);
    }
    printf("%lld\n", ans);
    return 0;
}