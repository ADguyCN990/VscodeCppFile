#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
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
char s[MAXN];
ll dp[MAXN][MAXN];
int n;
void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(dp, 0x3f, sizeof dp);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1)
                dp[l][r] = 1;
            else {
                if (s[l] == s[r])
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                for (int k = l; k < r; k++) {
                    //[l,k][k+1,r]
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }
    printf("%lld\n", dp[1][n]);
}

int main() {
    solve();
    return 0;
}