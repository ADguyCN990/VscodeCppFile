#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
typedef pair<int, int> pii;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

bool w[MAXN][MAXN];
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int wx[8] = {-1, 0, 1, 0};
int wy[8] = {0, 1, 0, -1};
int n, m, k, sx, sy, ex, ey;
int dis[MAXN][MAXN];

void init() {
    memset(w, false, sizeof w);
}

void map_init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dis[i][j] = -1;
        }
    }
    dis[sx][sy] = 0;
}

int bfs1() { //国际象棋
    map_init();
    queue<pii> q;
    q.emplace(sx, sy);
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (dis[a][b] != -1) continue;
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (w[a][b]) continue;
            dis[a][b] = dis[x][y] + 1;
            if (a == ex && b == ey) break;
            q.emplace(a, b);
        }
    }
    return dis[ex][ey];
}

int bfs2() {
    map_init();
    queue<pii> q;
    q.emplace(sx, sy);
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (dis[a][b] != -1) continue;
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (w[a][b]) continue;
            int wa = x + wx[i / 2], wb = y + wy[i / 2];
            if (w[wa][wb]) continue;
            dis[a][b] = dis[x][y] + 1;
            if (a == ex && b == ey) break;
            q.emplace(a, b);
        }
    }
    return dis[ex][ey];
}

void solve() {
    n = read(), m = read(), k = read();
    sx = read(), sy = read(), ex = read(), ey = read();
    init();
    while (k--) {
        int x = read(), y = read();
        w[x][y] = true;
    }
    int ans1 = bfs1();
    int ans2 = bfs2();
    printf("%d %d\n", ans1, ans2);
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}