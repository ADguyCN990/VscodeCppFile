#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 1e14
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
ll sum[MAXN];
set<ll> base;
unordered_map<ll, ll> vis;
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    base.insert(1);
    ll t = k;
    for (int i = 1; i <= 1000; i++) {
        ll num = t;
        if (num > 1e14) break;
        base.insert(num);
        t *= k;
    }
    //int len = base.size();
    //printf("len: %d\n", len);
    vis[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        for (ll x : base) {
            ans += vis[sum[i] - x];
        }
        vis[sum[i]]++;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}