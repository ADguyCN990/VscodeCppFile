#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll, ll> pii;
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
ll n, m;
pii p[MAXN];
void solve() {
    m = read(), n = read();
    for (int i = 1; i <= n; i++) p[i].first = read(), p[i].second = read();
    sort(p + 1, p + 1 + n);
    if (p[1].first != 1) {
        puts("1");
        return;
    }
    if (p[n].second != m) {
        printf("%lld\n", m);
        return;
    }
    for (int i = 1; i < n; i++) {
        ll u = p[i].second;
        ll v = p[i + 1].first;
        if (u + 1 != v && v > u) {
            printf("%lld\n", u + 1);
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}