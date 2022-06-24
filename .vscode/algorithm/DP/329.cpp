#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
#define MAXM 200005
#define mod 100000000
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
ll n, m;
ll a[MAXN];
vector<int> v;
vector<int> g[(1 << 12) + 5]; 
ll dp[2][(1 << 12) + 5];
bool judge(int st) {
    if (st & (st << 1)) return false;
    if (st & (st >> 1)) return false;
    return true;
}

bool work(int now, int pre) {
    if (now & pre) return false;
    return true;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int tmp = read();
            if (!tmp) ans += (1 << j);
        }
        a[i] = ans;
    }    
    for (int st = 0; st < (1 << m); st++)
        if (judge(st))
            v.pb(st);
    for (int now : v)   
        for (int pre : v)
            if (work(now, pre))
                g[now].pb(pre);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int now : v) {
            dp[i & 1][now] = 0;
            if (work(now, a[i])) {
                for (int pre : g[now]) {
                    dp[i & 1][now] = (dp[i & 1][now] + dp[(i - 1) & 1][pre]) % mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int now : v)
        ans = (ans + dp[n & 1][now]) % mod;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}