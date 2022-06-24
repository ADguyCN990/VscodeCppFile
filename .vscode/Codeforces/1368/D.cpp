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
int a[MAXN];
int cnt[25];

void work(int x) {
    for (int i = 20; i >= 0; i--) {
        int u = x >> i & 1;
        if (u)
            cnt[i]++;
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) work(a[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp = 0;
        for (int j = 0; j <= 20; j++) {
            if (!cnt[j]) continue;
            tmp += (1ll << j);
            cnt[j]--;
        }
        ans += tmp * tmp;
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}