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
int n, m;
int a[MAXN];
int b[MAXN];
int suf[MAXN];
map<int, ll> cnt;
void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
        cnt[suf[i]]++;
    }
    if (suf[1] != b[1]) {
        puts("0");
        return;
    }
    // puts("sufmn:");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", suf[i]);
    ll ans = 1;
    for (int i = 2; i <= m; i++)
        ans = ans * cnt[b[i]] % mod;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}