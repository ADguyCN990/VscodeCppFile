#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
int l, r;
int a[MAXN], al;
int dp[MAXN][MAXN];

int dfs(int pos, int pre, int limit) {
    if (!pos)
        return 1;
    if (!limit && ~dp[pos][pre]) return dp[pos][pre];
    int ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (i == 4) continue;
        if (pre == 6 && i == 2) continue;
        ans += dfs(pos - 1, i, limit && i == up);
    }
    return limit ? ans : dp[pos][pre] = ans;
}

int calc(int x) {
    al = 0;
    memset(dp, -1, sizeof dp);
    while (x) {
        a[++al] = x % 10;
        x /= 10;
    }
    return dfs(al, 0, 1);
}

void solve() {
    printf("%d\n", calc(r) - calc(l - 1));
}

int main() {
    while (scanf("%d%d", &l, &r), l || r) {
        solve();
    }
    return 0;
}