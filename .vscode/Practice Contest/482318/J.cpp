#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
struct node {
    ll x, y;
    friend bool operator< (node a, node b) {
        return a.x < b.x;
    }
}p[MAXN];

void solve() {
    n = read();
    ll mnx = INF, mxx = 0, mny = INF, mxy = 0;
    for (int i = 1; i <= n; i++) {
        ll x = read(), y = read();
        p[i].x = min(x, y);
        p[i].y = max(x, y);
        mnx = min(mnx, p[i].x), mxx = max(mxx, p[i].x);
        mny = min(mny, p[i].y), mxy = max(mxy, p[i].y);

    }
    ll ans = 1ll * (mxx - mnx) * (mxy - mny);
    ll tmp = mxy - mnx;
    sort(p + 1, p + 1 + n);
    mny = INF, mxy = 0;
    ans = min(ans, tmp * (p[n].x - p[1].x));
    for (int i = 1; i <= n; i++) {
        mxy = max(mxy, p[i].y), mny = min(mny, p[i].y);
        ans = min(ans, tmp * (max(mxy, p[n].x) - min(mny, i == n ? INF : p[i + 1].x)));
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}