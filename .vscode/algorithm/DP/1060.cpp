#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
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
ll dp[2][3];
ll n;
ll a[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    //空仓，0，要么前一天空仓，要么前两天卖出即前一天冷冻
    //持仓, 1，要么前一天持仓，要么前一天空仓后当前买入
    //冷冻，2，前一天持仓前一天卖出
    memset(dp, ~0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int pre = 1 - now;
        dp[now][0] = max(dp[pre][0], dp[pre][2]);
        dp[now][1] = max(dp[pre][1], dp[pre][0] - a[i]);
        dp[now][2] = dp[pre][1] + a[i];
    }
    printf("%lld\n", max(dp[n & 1][0], dp[n & 1][2]));
}

int main() {
    solve();
    return 0;
}