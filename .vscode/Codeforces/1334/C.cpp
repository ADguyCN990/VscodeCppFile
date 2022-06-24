#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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
ll a[MAXN], b[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
    a[0] = a[n], b[0] = b[n];
    ll ans = 0;
    ll mn = INF;
    for (int i = 1; i <= n; i++) {
        ll need = max(0ll, a[i] - b[i - 1]);
        ans += need;
        ll sub;
        if (b[i - 1] <= a[i])
            sub = b[i - 1];
        else
            sub = a[i];
        mn = min(sub, mn);
    }
    ans += mn;
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