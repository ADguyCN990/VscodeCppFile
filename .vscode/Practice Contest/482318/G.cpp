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
ll n, t;
ll a[MAXN];
void solve() {
    n = read(), t = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans = 0;
    ll r = -1;
    ll l;
    a[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        if (r == -1) {
            l = a[i];
            r = a[i];
        }
        if (r + t >= a[i + 1]) {
            r = a[i + 1];
        }
        else if (r + t < a[i + 1]) {
            r += t;
            ans += r - l;
            r = -1;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}