#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char s[MAXN][MAXN];
int vis[MAXN][MAXN];
ll n, m;
int cnt = 0;
typedef pair<int, int> pii;
void bfs(int x, int y)
{
    queue<pii> q;
    vis[x][y] = 1;
    q.push({x, y});
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int xx, yy;
            xx = x + dx[i];
            yy = y + dy[i];
            if (vis[xx][yy])
                continue;
            if (s[xx][yy] == '.')
                continue;
            if (xx > n || xx < 1 || yy > m || yy < 1)
                continue;
            vis[xx][yy] = 1;
            q.push({xx, yy});
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i] + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && s[i][j] == 'W')
            {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}