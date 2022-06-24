#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define mod 998244353
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

ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t % mod   ;
        t = t * t  % mod   ;
        k >>= 1;
    }
    return res;
}
pii p[MAXN];
bool col[MAXN], row[MAXN];
ll n, m, k, q;

void init() {
    for (int i = 1; i <= n; i++) row[i] = false;
    for (int i = 1; i <= m; i++) col[i] = false;
}
void solve() {
    n = read(), m = read(), k = read(), q = read();
    init();
    for (int i = 1; i <= q; i++) {
        p[i].first = read(), p[i].second = read();
    }
    reverse(p + 1, p + 1 + q);
    //被覆盖的不算
    ll cnt = 0;
    ll cntrow = n, cntcol = m;
    for (int i = 1; i <= q; i++) {
        int u = p[i].first; //第u行
        int v = p[i].second; //第v列
        bool flag = true;
        if (!cntrow || !cntcol)
            flag = false;
        if (row[u] && col[v])
            flag = false;
        if (!row[u])
            cntrow--, row[u] = true;
        if (!col[v])
            cntcol--, col[v] = true;
        if (flag)
            cnt++;
    }
    printf("%lld\n", quickpow(k, cnt));
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}