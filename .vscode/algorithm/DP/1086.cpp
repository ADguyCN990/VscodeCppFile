#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
int l, r, mod;
int a[MAXN], al;
int dp[MAXN][105];

int dfs(int pos, int sum, int limit) {
    if (!pos) {
        if (sum % mod == 0) return 1;
        return 0;
    }
    if (!limit && ~dp[pos][sum]) return dp[pos][sum];
    int ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        ans += dfs(pos - 1, sum + i, limit && i == up);
    }
    return limit ? ans : dp[pos][sum] = ans;
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
    while (scanf("%d%d%d", &l, &r, &mod) != EOF) {
        solve();
    }
    return 0;
}