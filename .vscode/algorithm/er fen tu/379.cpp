#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 405
#define MAXM 30005
int n,m;
int vis[MAXN],match[MAXN];
int mp[MAXN][MAXN];

bool find(int now)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&mp[now][i])
        {
            vis[i]=1;
            if(match[i]==0||find(match[i]))
            {
                match[i]=now;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]=1;
    }
    int ans=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mp[i][j]|=mp[i][k]&mp[k][j];

    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            ans++;
    }
    cout<<n-ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}