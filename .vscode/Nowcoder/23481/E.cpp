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
ll n;
ll a[MAXN], b[MAXN], h[MAXN], c[MAXN];
void solve() {
    n = read();
    int mx = 0, mxid = 0;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read(), b[i] = read(), h[i] = read();
        c[i] = b[i] + h[i];
        if (a[i] > mx) {
            x = mx;
            mx = a[i];
            mxid = i;
        }
        else if (a[i] <= mx && a[i] > x) {
            x = a[i];
        }
    }
    //printf("mx: %d mxid: %d x:%d\n", mx, mxid, x);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i != mxid) {
            ans += max(0ll, mx - c[i] + 1);
        }
        else if (i == mxid) {
            ans += max(0ll, x - c[i] + 1);
        }
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