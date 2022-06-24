#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10
int mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;
int ans;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void init()
{
    memset(vis, 0, sizeof vis);
    ans = 0;
}

void dfs(int x, int y, int sum)
{
    if (y == m + 1)
    {
        dfs(x + 1, 1, sum);
        return;
    }
        
    if (x == n + 1)
    {
        ans = max(ans, sum);
        return;
    }
    dfs(x, y + 1, sum);
    if (vis[x][y]==0)
    {
        for (int i = 0; i < 8; i++)
            vis[x + dx[i]][y + dy[i]]++;
        dfs(x, y + 1, sum + mp[x][y]);
        for (int i = 0; i < 8; i++)
            vis[x + dx[i]][y + dy[i]]--;
    }
}

void solve()
{
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    dfs(1,1,0);
    //dfs(1, 1, mp[1][1]);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}