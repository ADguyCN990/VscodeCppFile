#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define mod 1000000007
ll n,m;
ll dp[MAXN][MAXN];
//反射后依然会继续反射
void init()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][1]=1;
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i]=1;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        init();
        //一个粒子只会分成两个，继续向前，反射回去衰变程度+1
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                dp[i][j]=(dp[i-1][j]+dp[n-i][j-1])%mod;
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}