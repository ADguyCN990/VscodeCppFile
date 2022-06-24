#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
char mp[MAXN][MAXN];
int dis[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;
char cs[] = "\\/\\/";
int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
int bfs()
{
    deque<pii> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[0][0] = 0;
    q.push_front({0, 0});
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop_front();
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {

            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m)
                continue;

            int xx = x + ix[i], yy = y + iy[i];
            int d = dis[x][y] + (mp[xx][yy] != cs[i]);

            if (d < dis[a][b])
            {
                dis[a][b] = d;

                if (mp[xx][yy] != cs[i])
                    q.push_back({a, b});
                else
                    q.push_front({a, b});
            }
        }
    }
    return dis[n][m];
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mp[i];
    int ans = INF;
    ans = bfs();
    if (ans == INF)
        cout << "NO SOLUTION" << endl;
    else
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