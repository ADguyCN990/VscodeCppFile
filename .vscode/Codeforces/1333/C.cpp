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
ll a[MAXN];
map<ll, ll> pos;
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    pos[0] = 0;
    ll sum = 0;
    ll ans = 0;
    ll now = -1;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (pos.count(sum))
            now = max(now, pos[sum]);//[now + 1, i - 1]这段可选
        ans += i - now - 1;
        pos[sum] = i;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}