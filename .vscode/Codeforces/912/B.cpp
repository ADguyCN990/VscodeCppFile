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
ll n, k;
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
    n = read(), k = read();
    if (k == 1) {
        printf("%lld\n", n);
        return;
    }
    ll lg;
    for (int i = 63; i >= 0; i--) {
        int u = n >> i & 1;
        if (u) {
            lg = i;
            break;
        }
    }
    printf("%lld\n", quickpow(2, lg + 1) - 1);
}

int main() {
    solve();
    return 0;
}