#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 35
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
ll n;
ll a[MAXN];
ll dp[MAXN][MAXN];
int rt[MAXN][MAXN];

void dfs(int now, int l, int r) {
    if (l > r) return;
    printf("%d ", now);
    dfs(rt[l][now - 1], l, now - 1);
    dfs(rt[now + 1][r], now + 1, r);
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(dp, ~0x3f, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1) {
                dp[l][r] = a[l];
                rt[l][r] = l;
            }
            else {
                for (int k = l; k <= r; k++) { //枚举一段区间内的根节点
                    ll lscore = k == l? 1ll: dp[l][k - 1];
                    ll rscore = k == r? 1ll: dp[k + 1][r];
                    ll score = lscore * rscore + a[k];
                    if (score > dp[l][r]) {
                        dp[l][r] = score;
                        rt[l][r] = k;
                    }
                }   
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    dfs(rt[1][n], 1, n);
}

int main() {
    solve();
    return 0;
}