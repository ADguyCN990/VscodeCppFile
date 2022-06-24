#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
ll E = -INF, N = INF, W = INF, S = - INF;
ll m, x, y, h;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int main() {
    m = read();
    for (int i = 1; i <= m; i++) {
        x = read(), y = read(), h = read();
        ll e = y + h, w = y - h, n = x - h, s = x + h;
        E = max(E, e);
        W = min(W, w);
        N = min(N, n);
        S = max(S, s);
    }
    ll x = N + S >> 1;
    ll h = (S - N + 1) / 2;
    ll y = W + E >> 1;
    h = max(h, (E - W + 1) / 2);
    printf("%lld %lld %lld\n", x, y, h);
    return 0;
}