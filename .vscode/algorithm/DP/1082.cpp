#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
int read() {
    int_fast8_t x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int l, r;
int a[MAXN], al;
int dp[MAXN][MAXN];

int dfs(int pos, int pre, int limit) {
    if (!pos) {
        return 1;
    }
    if (!limit && ~dp[pos][pre]) return dp[pos][pre];
    int ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (i < pre) continue;
        ans += dfs(pos - 1, i, limit && i == up);
    }
    return limit ? ans : dp[pos][pre] = ans;
}

int calc(int x) {
    memset(dp, -1, sizeof dp);
    al = 0;
    while (x) {
        a[++al] = x % 10;
        x /= 10;
    }
    return dfs(al, -1, 1);
}

void solve() {
    printf("%d\n", calc(r) - calc(l - 1));
}

int main() {
    while (scanf("%d%d", &l, &r)) {
        solve();
    }
    return 0;
}