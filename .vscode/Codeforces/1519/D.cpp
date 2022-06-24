#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ll long long
ll a[MAXN];
ll b[MAXN];
ll dp[MAXN][MAXN];
ll n;
ll dfs(int l,int r)
{
    if(l>=r) return 0;
    if(dp[l][r]!=-0x3f3f3f3f) return dp[l][r];
    return dp[l][r]=dfs(l+1,r-1)+a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r];
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=-0x3f3f3f3f;
        }       
    }
}

void solve()
{
    cin>>n;
    init();       
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll sum=0;
    ll extra=0;
    for(int i=1;i<=n;i++) sum+=a[i]*b[i];
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            if(j>n) break;
            extra=max(extra,dfs(i,j));           
        }
    }
    cout<<sum+extra<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int T;
   // cin>>T;
    //while(T--)
    //{
        solve();
   // }
    return 0;
}