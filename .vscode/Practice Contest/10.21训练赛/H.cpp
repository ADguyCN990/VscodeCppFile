#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
ll dp[MAXN][MAXN];
ll n,V,M;
void solve()
{
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++)
    {
        ll v,m,w;
        cin>>v>>m>>w;
        for(int j=V;j>=v;j--)
        {
            for(int k=M;k>=0;k--)
            {
                if(j-v-(m-k)>0&&k-m<0&&j>v)
                {
                    dp[j][k]=max(dp[j-v-(m-k)][0]+w,dp[j][k]);
                }
                else if(j>v&&k>=m)
                {
                    dp[j][k]=max(dp[j][k],dp[j-v][k-m]+w);
                }
            }
        }
    }
    cout<<dp[V][M]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}