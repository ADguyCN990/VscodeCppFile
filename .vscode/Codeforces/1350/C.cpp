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
int n;
int a[MAXN];
vector<int> fac[MAXN];

ll quickpow(ll m, ll k) {
    ll res = 1 , t = m;
    while (k) {
        if (k&1) res = res * t    ;
        t = t * t     ;
        k >>= 1;
    }
    return res;
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    cnt++;
                }
                fac[j].pb(cnt);
            }
        }
        if (x > 1)
            fac[x].pb(1);
    }
    ll ans = 1;
    for (int i = 2; i <= 200000; i++) {
        int len = fac[i].size();
        if (len < n - 1) continue;
        sort(fac[i].begin(), fac[i].end());
        if (len == n - 1)
            ans = ans * quickpow(i, fac[i][0]);
        else if (len == n)
            ans = ans * quickpow(i, fac[i][1]);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}