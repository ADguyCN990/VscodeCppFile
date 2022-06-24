#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define INF 0x3f3f3f3f
ll mp[MAXN][MAXN];//存图
ll dp[MAXN][MAXN];//floyd
ll pos[MAXN][MAXN];
int n,m;
ll ans=INF;
int path[MAXN];
int cnt;//记录最小环的长度

void get(int i,int j)
{
    if(pos[i][j]==0) return;
    int k=pos[i][j];
    get(i,k);
    path[++cnt]=k;
    get(k,j);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=INF;
    for(int i=0;i<=n;i++)
        mp[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=mp[v][u]=min(mp[u][v],w);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=mp[i][j];
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                if((dp[i][j]+mp[k][i]+mp[j][k])<ans)
                {
                    ans=(dp[i][j]+mp[k][i]+mp[j][k]);
                    cnt=0;
                    path[++cnt]=k;
                    path[++cnt]=i;
                    get(i,j);
                    path[++cnt]=j;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][j]>dp[i][k]+dp[k][j])
                {
                    pos[i][j]=k;
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    if(ans==INF)
        cout<<"No solution.";
    else
        for(int i=1;i<=cnt;i++)
            cout<<path[i]<<" ";
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // cin>>T;
    // while(T--)
    // {
        solve();
    //}

    return 0;
}