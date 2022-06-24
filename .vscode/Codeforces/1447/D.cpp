#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
ll dp[MAXN][MAXN];
ll n,m;
char s[MAXN];char t[MAXN];
//LCS(C,D)-|C|-|D|
void solve()
{
    cin>>n>>m;
    cin>>s+1;
    cin>>t+1;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char a,b;
            a=s[i];b=t[j];
            if(a==b)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);//最长公共子序列长度+1，贡献+2
            else
                dp[i][j]=max(max(dp[i-1][j],dp[i][j-1])-1,0ll);//最次最次也不会是负数
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(dp[i][j],ans);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}