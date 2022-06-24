#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int mp[MAXN][MAXN];
int d[MAXN];
int n;
double ans;
int cnt;
int vis[MAXN];
void dfs(int now)
{
    cnt++;
    if(!vis[now])
        vis[now]=cnt;
    for(int i=1;i<=n;i++)
    {
        if(mp[now][i])
        {
            mp[now][i]--,mp[i][now]--;
            dfs(i);
        }
    }
}

void solve()
{
    memset(mp,0,sizeof(mp));
    memset(d,0,sizeof(d));
    memset(vis,0,sizeof(vis));
    ans=0;
    cnt=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]++,mp[v][u]++;
        d[u]++,d[v]++;
    }
    dfs(1);
    for(int i=2;i<=n;i++)
    {
        cout<<vis[i]<<" ";
        ans+=vis[i];
    }
    cout<<endl;
    cout<<"!!!"<<ans*1.0/(n-1)<<endl;
    // for(int i=1;i<=cnt;i++)
    //     cout<<tmp[i]<<" ";
    // cout<<endl;
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