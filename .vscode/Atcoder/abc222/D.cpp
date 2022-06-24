#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define MAXN 3005
ll dp[MAXN][MAXN];//第i个末尾是j的方案数
ll a[MAXN];ll b[MAXN];
ll n;
void solve()
{
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=3000;j++) dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
        if(i!=n)
        {
            for(int j=a[i];j<=b[i];j++)
            {
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            }
        }
    }
    for(int i=a[n];i<=b[n];i++) sum=(sum+dp[n][i])%mod;
    cout<<sum<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}