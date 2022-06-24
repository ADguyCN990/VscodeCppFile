#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
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
int n, x;
int a[MAXN];
ll pre[MAXN];

void solve() {
    n = read(), x = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) pre[i] = -INF;
    for (int i = 1; i <= n; i++) {
        ll now = 0;
        for (int j = i; j <= n; j++) {
            int len = j - i + 1;
            now += a[j];
            pre[len] = max(pre[len], now);
        }
    }
    for (int k = 0; k <= n; k++) {
        ll ans = 0;
        for (int len = 1; len <= n; len++) {
            ans = max(ans, pre[len] + min(k, len) * x);
        }
        printf("%lld ", ans);
    }
    puts("");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}