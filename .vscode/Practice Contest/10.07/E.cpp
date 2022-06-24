#pragma comment(linker, "/STACK:10240000000,10240000000")

#include <bits/stdc++.h>

using namespace std;
int a[1000005] = {}, dp[1000005] = {};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sum = 0;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> dp(sum / 2 + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = sum / 2; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }

    cout << abs(sum - dp[sum / 2] * 2) << endl;
}