#include<bits/stdc++.h>
using namespace std;
#define MAXN 15
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int l, r;
int a[MAXN], al;
int dp[MAXN][MAXN]; //第i位数为j时的方案数

int dfs(int pos, int pre, int lead, int limit) {
    if (!pos) {
        //0也算一种方案，所以不用特判前导零
        return 1;
    }
    if (!limit && !lead && ~dp[pos][pre]) return dp[pos][pre];
    int ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        if (abs(i - pre) < 2) continue;
        if (lead && !i)
            ans += dfs(pos - 1, -2, 1, limit && i == up);
        else
            ans += dfs(pos - 1, i, 0, limit && i == up);
    }
    return limit ? ans : (lead ? ans : dp[pos][pre] = ans);
}

int calc(int x) {
    memset(dp, -1, sizeof dp);
    al = 0;
    while (x) {
        a[++al] = x % 10;
        x /= 10;
    }
    return dfs(al, -2, 1, 1);
}

void solve() {
    l = read(), r = read();
    printf("%d\n", calc(r) - calc(l - 1));
}

int main() {
    solve();
    return 0;
}