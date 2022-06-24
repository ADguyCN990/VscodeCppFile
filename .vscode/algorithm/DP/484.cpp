#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll dpl[MAXN], dpr[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    dpl[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll mx = 0;
        for (int j = 1; j < i; j++) 
            if (a[j] < a[i])
                mx = max(mx, dpl[j]);
        dpl[i] = mx + 1;
    }
    dpr[n] = 0;
    for (int i = n - 1; i; i--) {
        ll mx = -1;
        for (int j = n; j > i; j--) 
            if (a[j] < a[i])
                mx = max(mx, dpr[j]);
        dpr[i] = mx + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dpl[i] + dpr[i]);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}