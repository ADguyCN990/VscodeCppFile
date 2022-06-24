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
ll n, m;
ll a[25][25];
ll dp[25][25];
int path[25], cnt;

void dfs(int now, int v) {
    if (!now) return; //所有物品都选完了
    for (int i = 0; i <= m; i++) {
        if (v >= i && dp[now][v] == dp[now - 1][v - i] + a[now][i]) {
            path[now] = i;
            dfs(now - 1, v - i);
            return;
        }
    }
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j]; //状态转移，先假设不选当前组内物品
            for (int k = 1; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
            }
        }
    }
    printf("%lld\n", dp[n][m]);
    // for (int i = n, j = m; i >= 1; i--) {
    //     for (int k = 0; k <= m; k++) {
    //         if (j >= k && dp[i][j] == dp[i - 1][j - k] + a[i][k]) {
    //             j -= k;
    //             path[i] = k;
    //             break; //同一组内只能选一个，选完后就break掉
    //         }
    //     }
    // }
    dfs(n, m);
    for (int i = 1; i <= n; i++) printf("%d %d\n", i, path[i]);
}

int main() {
    solve();
    return 0;
}