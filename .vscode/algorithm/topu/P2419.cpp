#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
int mp[MAXN][MAXN];
ll n,m;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) mp[i][i]=1;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]=mp[i][j]||(mp[i][k]&&mp[k][j]);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int temp=1;
        for(int j=1;j<=n;j++)
        {
            temp=temp&&(mp[i][j]||mp[j][i]);
        }
        ans+=temp;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}