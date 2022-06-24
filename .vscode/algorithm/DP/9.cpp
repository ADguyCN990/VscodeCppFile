#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n, V;
ll v[MAXN][MAXN], w[MAXN][MAXN], dp[MAXN][MAXN], cnt[MAXN];
void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) {
        cnt[i] = read();
        for (int j = 1; j <= cnt[i]; j++)
            v[i][j] = read(), w[i][j] = read();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= cnt[i]; k++) {
                if (j >= v[i][k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    printf("%lld\n", dp[n][V]);
}

int main() {
    solve();
    return 0;
}