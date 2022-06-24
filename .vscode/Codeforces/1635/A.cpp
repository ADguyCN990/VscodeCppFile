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
int cnt[35];

void work(ll x) {
    for (int i = 31; i >= 0; i--) {
        int u = x >> i & 1;
        cnt[i] += u;
    }
}

void solve() {
    n = read();
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        ll x = read();
        work(x);
    }
    ll ans = 0;
    for (int i = 0; i <= 31; i++) {
        if (cnt[i])
            ans += (1ll << i);
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