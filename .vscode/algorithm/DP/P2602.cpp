#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
#define ll long long
ll l, r;
ll a[MAXN], al;
ll dp[MAXN][MAXN]; //前i位num出现过j次的方案数

ll dfs(ll pos, ll cnt, ll num, ll lead, ll limit) {
    if (!pos) {
        if (!num && lead)
            return 1; //所有位上都是0
        else
            return cnt; //返回num出现过的次数
    }
    if (!limit && !lead && ~dp[pos][cnt]) return dp[pos][cnt];
    ll ans = 0;
    ll up = limit ? a[pos] : 9;
    for (ll i = 0; i <= up; i++) {
        ll nxt;
        if (i == num) {
            //如果i是要找的那个数
            if (!num) //要找的数是0，那么前导零的限制必须已解除
                nxt = cnt + !lead;
            else
                nxt = cnt + 1;
        }
        else
            nxt = cnt;
        ans += dfs(pos - 1, nxt, num, lead && !i, limit && i == up);
    }
    return limit ? ans : (lead ? ans : dp[pos][cnt] = ans);
}

ll calc(ll n, ll x) {
    memset(dp, -1, sizeof dp);
    al = 0;
    while (n) {
        a[++al] = n % 10;
        n /= 10;
    }
    return dfs(al, 0, x, 1, 1);
}

void solve() {
    scanf("%lld%lld", &l, &r);
    for (ll i = 0; i <= 9; i++) {
        printf("%lld ", calc(r, i) - calc(l - 1, i));
    }
    puts("");
}

int main() {
    solve();
    return 0;
}