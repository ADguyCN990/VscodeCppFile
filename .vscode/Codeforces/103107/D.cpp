#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
#define mod 1000003
ll n;
ll b[MAXN];
ll a[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r; r = l + len - 1, r <= n; l++) {
            if (len == 1) {
                a[l][r] = b[l];
            }
            else {
                for (int k = l; k < r; k++) {
                    //[l, k] [k + 1, r]
                    if ((a[l][k] - a[k + 1][r]) * (a[l][k] - a[k + 1][r]) + dp[l][k] + dp[k + 1][r] > dp[l][r]) {
                        dp[l][r] = (a[l][k] - a[k + 1][r]) * (a[l][k] - a[k + 1][r]) + dp[l][k] + dp[k + 1][r];
                        a[l][r] = a[l][k] * a[k + 1][r] % mod;
                    }
                   

                }
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    return 0;
}