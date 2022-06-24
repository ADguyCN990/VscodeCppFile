#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007
#define MAXN 70
ll dp[MAXN][MAXN];
ll r;
int a[MAXN], al;

ll dfs(int pos, int cnt, int limit) {
    if (!pos) {
        return max(1ll, (ll)cnt);
    }
    if (!limit && ~dp[pos][cnt]) return dp[pos][cnt];
    ll ans = 1;
    int up = limit ? a[pos] : 1;
    for (int i = 0; i <= up; i++) {
        int t = cnt;
        if (i) t++;
        ans = ans * dfs(pos - 1, t, limit && i == up) % mod;
    }
    return limit ? ans : dp[pos][cnt] = ans;
}

ll calc(ll x) {
    memset(dp, -1, sizeof dp);
    al = 0;
    while (x) {
        a[++al] = x % 2;
        x /= 2;
    }
    return dfs(al, 0, 1);
}

int main() {
    scanf("%lld", &r);
    printf("%lld\n", calc(r));
    return 0;
}

