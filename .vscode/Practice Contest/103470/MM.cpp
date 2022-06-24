#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
int n;
ll a[MAXN];
unordered_map<ll, ll> cnt;
ll read(){
    ll x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-') f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while  (ch>='0' && ch<='9');
    return x * f;
}

void solve() {
    scanf("%d", &n);
    cnt.clear();
    ll mx = -INF, mn = INF;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        if (a[i] > mx) {
            mx = a[i];
        }
        if (a[i] < mn) {
            mn = a[i];
        }
        cnt[a[i]]++;
    }
    if (n == 1) {
        printf("%lld\n", a[1]);
        return;
    }
    ll ans = 0;
    ans += mx - mn;
    if (mx == mn) {
        ans += (cnt[mx] - 2) * abs(mx);
    }
    else {
        ans += (cnt[mx] - 1) * abs(mx);
        ans += (cnt[mn] - 1) * abs(mn);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == mn || a[i] == mx) continue;
        ans += abs(a[i]);
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}