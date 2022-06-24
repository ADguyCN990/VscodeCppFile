#include<bits/stdc++.h>
using namespace std;
int n = 10;
#define MAXN 15
#define ll long long
typedef pair<int, int> pii;
int sx, sy, ex, ey;
char g[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int sx, int sy) {
    memset(dis, -1, sizeof dis);
    dis[sx][sy] = 0;
    queue<pii> q;
    q.emplace(sx, sy);
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (dis[a][b] != -1) continue;
            if (a < 1 || a > n || b < 1 || b > n) continue;
            if (g[a][b] == 'R') continue;
            dis[a][b] = dis[x][y] + 1;
            q.emplace(a, b);
        }
    }
}

int main() {
    for (int i = 1; i <= n; i++)
        scanf("%s", g[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 'L')
                sx = i, sy = j;
            if (g[i][j] == 'B')
                ex = i, ey = j;
        }
    }
    bfs(sx, sy);
    printf("%d\n", dis[ex][ey] - 1);
    return 0;
}
