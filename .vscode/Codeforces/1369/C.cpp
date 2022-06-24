#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n, k;
ll a[MAXN];
ll w[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= k; i++) w[i] = read();
    sort(w + 1, w + 1 + k, greater<>());
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    ll ans = 0;
    for (int i = k; i >= 1; i--) {
        if (w[i] == 1) {
            ans += a[r] * 2;
            r --;
        }
        else {
            k = i;
            break;
        }
    }
    for (int i = 1; i <= k && l <= r; i++) {
        ans = ans + a[l] + a[r];
        r--;
        l += w[i] - 1;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}