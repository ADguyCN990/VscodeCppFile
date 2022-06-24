#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
ll n,m;
char mp[MAXN][MAXN];
ll dp[MAXN][MAXN];
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=0;
        }
    }
}

void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='*') dp[i][j]=1;
        }
    }
    for(int i=n-1;i>0;i--)
    {
        for(int j=2;j<m;j++)
        {
            if(mp[i][j]=='*')
            dp[i][j]=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]})+1;
        }
    }
    
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]=='*')
            ans+=dp[i][j];
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}