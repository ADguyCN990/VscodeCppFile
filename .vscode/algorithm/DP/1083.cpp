#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 40
int read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int l, r, k, b;
int a[MAXN], al;
int dp[MAXN][MAXN];

int dfs(int pos, int cnt, int limit) {
    //枚举完所有数，看1出现的次数是否等于k
    if (!pos) return cnt == k;
    //当前限制以解除，返回记忆化结果
    if (!limit && ~dp[pos][cnt]) return dp[pos][cnt];
    //这个状态还没出现过，往下搜
    int ans = 0;
    int up = limit ? a[pos] : b - 1;
    for (int i = 0; i <= up; i++) {
        if (cnt + i > k) continue;
        if (i > 1) continue;
        ans += dfs(pos - 1, cnt + i, limit && i == up);
    }
    return limit ? ans : dp[pos][cnt] = ans;
}

int calc(int x) {
    al = 0;
    memset(dp, -1, sizeof dp);
    while (x) {
        a[++al] = x % b;
        x /= b;
    }
    return dfs(al, 0, 1);
}

void solve() {
    l = read(), r = read(), k = read(), b = read();
    printf("%d\n", calc(r) - calc(l - 1));
}

int main() {
    solve();
    return 0;
}
