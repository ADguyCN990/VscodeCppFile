#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define mod 998244353
int dp[MAXN][5];
int n;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    dp[0][0]=1;
    dp[1][1]=0;dp[1][2]=0;
    //dp[i][0] 长度为i，无尖角的情况
    //dp[i][1] 长度为i，尖角向上的情况
    //dp[i][2] 长度为i，尖角向下的情况
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][1]=(dp[i-2][0]+dp[i-2][2])%mod;
        dp[i][2]=(dp[i-2][0]+dp[i-2][1])%mod;
    }
    cout<<dp[n][1];
    return 0;
}