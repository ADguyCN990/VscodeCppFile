#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll l, r;
int a[MAXN], al;
ll dp[MAXN][5];

ll dfs(int pos, int cnt, int limit) {
    if (!pos)
        return 1;
    if (!limit && ~dp[pos][cnt]) return dp[pos][cnt];
    ll ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (i && cnt + 1 > 3) continue;
        int t;
        if (!i)
            t = cnt;
        else 
            t = cnt + 1;
        ans += dfs(pos - 1, t, limit && i == up);
    }
    return limit ? ans : dp[pos][cnt] = ans;
}

ll calc(ll x) {
    al = 0;
    memset(dp, -1, sizeof dp);
    while (x) {
        a[++al] = x % 10;
        x /= 10;
    }
    return dfs(al, 0, 1); 
}

void solve() {
    l = read(), r = read();
    printf("%lld\n", calc(r) - calc(l - 1));
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
}