#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int a[1005];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}