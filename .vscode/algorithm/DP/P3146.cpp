#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 250
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
ll dp[MAXN][MAXN];
ll n;
ll a[MAXN];
void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    ll ans = 0;
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (l == r)
                dp[l][r] = a[l], ans = max(ans, a[l]);
            else {
                for (int k = l; k < r; k++) {
                    //[l,k][k+1,r]
                    int lmx = dp[l][k];
                    int rmx = dp[k + 1][r];
                    //printf("lmx: %d rmx: %d\n", lmx, rmx);
                    if (lmx == 0 || rmx == 0 || lmx != rmx) continue;
                    
                    dp[l][r] = lmx + 1;
                    ans = max(ans, dp[l][r]);
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}