#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, ans;
int vis[20][20];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //方向数组
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //方向数组
void dfs(int x, int y, int step)          //step记录当前走了几个格子
{
    if (step == n * m)
    {          //已遍历完所有的格子
        ans++; //答案加一
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0)
        {                    //判断
            vis[xx][yy] = 1; //标记
            dfs(xx, yy, step + 1);
            vis[xx][yy] = 0; //回溯
        }
    }
}

void solve()
{
    ans = 0; 
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> a >> b;
    vis[a][b] = 1; //标记起点
    dfs(a, b, 1);
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    { 
        solve();
    }
    return 0;
}
