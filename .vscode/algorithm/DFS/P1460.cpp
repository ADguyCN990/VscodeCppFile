#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30
int n, m;
int a[MAXN];
int b[MAXN][MAXN];
int vis[MAXN];
int sum[MAXN];
int ans =MAXN;
int path[MAXN];
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] < a[i])
            return false;
    }
    return true;
}

void dfs(int cnt,int start)
{
    if(start>m) return;
    if(cnt>=ans) return;
    if(check()&&cnt<ans)
    {
        ans=cnt;
        int t=0;
        for(int i=1;i<=m;i++)
            if(vis[i])
                path[++t]=i;
        return;
    }
    for(int i=start+1;i<=m;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            for(int j=1;j<=n;j++)
                sum[j]+=b[i][j];
            dfs(cnt+1,i);
            vis[i]=0;
            for(int j=1;j<=n;j++)
                sum[j]-=b[i][j];
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    for(int i=1;i<=m;i++)
    {
        vis[i]=1;
        for(int j=1;j<=n;j++)
            sum[j]+=b[i][j];
        dfs(1,i);
        vis[i]=0;
        for(int j=1;j<=n;j++)
            sum[j]-=b[i][j];
    }

    cout << ans << " ";
    for(int i=1;i<=ans;i++) cout<<path[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}