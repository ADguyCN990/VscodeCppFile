#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
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
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(dp, 0x3f, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1)
                dp[l][r] = 1;
            else if (len == 2) {
                if (a[l] == a[r])
                    dp[l][r] = 1;
                else
                    dp[l][r] = 2;
            }
            else {
                for (int k = l; k < r; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                if (a[l] == a[r])
                    dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            }
        }
    }
    printf("%lld\n", dp[1][n]);   
}
int main() {
    solve();
    return 0;
}