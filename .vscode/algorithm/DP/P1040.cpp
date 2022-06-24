#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 35
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

void dfs(int l, int r) {
    if (l > r) return;
    int root = rt[l][r];
    printf("%d ", root);
    dfs(l, root - 1);
    dfs(root + 1, r);
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1) 
                dp[l][r] = a[l], rt[l][r] = l;
            else {
                for (int k = l; k <= r; k++) {
                    //[l,k][k+1,r]
                    ll lscore = 0, rscore = 0;
                    lscore = k == l? 1ll : dp[l][k - 1];
                    rscore = k == r? 1ll : dp[k + 1][r];
                    if (lscore * rscore + a[k] > dp[l][r]) {
                        dp[l][r] = lscore * rscore + a[k];
                        rt[l][r] = k;
                    }
                }
            }
            
        }
    }
    printf("%lld\n", dp[1][n]);
    dfs(1, n);
}

int main() {
    solve();
    return 0;
}