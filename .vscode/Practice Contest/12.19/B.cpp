#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define mod 1000000007
int mp[MAXN][MAXN];
int vis[MAXN][MAXN];//能否作为唯一终点
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
ll dp[MAXN][MAXN];
int n,m;


ll dfs(int x,int y,int len)
{
    ll ans=0;
    if(dp[x][y]) return dp[x][y];
    bool flag=false;
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<1||a>n||b<1||b>m) continue;
        if(mp[a][b]==mp[x][y]+1)
        {
            flag=true;//还能继续往下搜
            ans=(ans+dfs(a,b,len+1))%mod;
        }
    }
    if(len>=4 && !flag)//长度满足条件且走进了死胡同
    {
        // return 1;+
    }
    dp[x][y]=(dp[x][y]+ans)%mod;
    return dp[x][y];
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            vis[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int a=i+dx[k],b=j+dy[k];
                if(a<1||a>n||b<1||b>m)
                {
                    continue;
                }
                if(mp[a][b]==mp[i][j]-1)
                    vis[i][j]=0;
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j])
            {
                ans=(ans+dfs(i,j,1))%mod;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}