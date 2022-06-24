#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define ll long long
ll t,n;
ll a[MAXN];
ll dp[MAXN][MAXN];//走到i喝了j瓶药后的血量

void solve()
{
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    cin>>n;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(dp[i-1][j-1]+a[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
            }
        }       
    }
    int cnt=0;
    for(int j=1;j<=n;j++)
    {
        if(dp[n][j]>=0)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cin>>t;
    //while(t--)
    //{
        solve();
    //}
    return 0;
}