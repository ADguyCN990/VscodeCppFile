#include<bits/stdc++.h>

using namespace std;
int dp[1010];

int main() 
{

    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = dp[2] = 4;
    if (n & 1)
        for (int i = 3; i <= n; i += 2)
            dp[i] = dp[i - 2] + 4 * (i + 1) / 2;
    else
        for (int i = 4; i <= n; i += 2)
            dp[i] = dp[i - 4] + 4 * i / 2;
    cout << dp[n];

    return 0;
}
