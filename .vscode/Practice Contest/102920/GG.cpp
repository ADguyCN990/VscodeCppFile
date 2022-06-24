#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define INF 0x3f3f3f3f3f3f3f3f
ll n, d;
ll a[MAXN];
ll read(){
    ll x = 0, f = 1;char ch;
    do{ch=getchar();if (ch=='-')f=-1;}while (ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x * f;
}
int main() {
    n = read(), d = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll lx = INF, rx = -INF;
    for (int i = 1; i <= n; i++) {
        lx = min(lx, a[i] - (i - 1) * d);
        rx = max(rx, a[i] - (i - 1) * d);
    }
    ll ans = rx - lx;
    reverse(a + 1, a + 1 + n);
    lx = INF, rx = -INF;
    for (int i = 1; i <= n; i++) {
        lx = min(lx, a[i] - (i - 1) * d);
        rx = max(rx, a[i] - (i - 1) * d);
    }
    ans = min(ans, rx - lx);
    if (ans & 1)
        printf("%lld.5\n", ans / 2);
    else
        printf("%lld.0\n", ans / 2);
    return 0;
}