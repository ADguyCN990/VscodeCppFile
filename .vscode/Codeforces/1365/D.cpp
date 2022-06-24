#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char s[MAXN][MAXN];
int a[MAXN][MAXN]; //空地0，障碍1，好人2，坏人3
int n, m;
bool vis[MAXN][MAXN];

void input() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.')
                a[i][j] = 0;
            else if (s[i][j] == '#')
                a[i][j] = 1;
            else if (s[i][j] == 'G')
                a[i][j] = 2;
            else if (s[i][j] == 'B')
                a[i][j] = 3;
        }
    }
       
}

bool check() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (a[x][y] == 3) {
                for (int i = 0; i < 4; i++) {
                    int xx = x + dx[i], yy = y + dy[i];
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if (a[xx][yy] == 2)
                        return false;
                    if (a[xx][yy] == 0)
                        a[xx][yy] = 1;
                }
            }
        }
    }
    return true;
}

void bfs() {
    queue<pii> q;
    q.emplace(n, m);
    vis[n][m] = true;
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || a[xx][yy] == 1) continue;
            q.emplace(xx, yy);
            vis[xx][yy] = true;
        }
    }
}

void solve() {
    memset(vis, false, sizeof vis);   
    input();
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%d ", a[i][j]);
    //     }
    //         puts("");
    // }
    bool flag = check();
    if (!flag) {
        puts("NO");
        return;
    }
    bfs();
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (vis[i][j])
    //             printf("1 ");
    //         else
    //             printf("0 ");
    //     }
    //     puts("");
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 2 && (!vis[i][j] || a[n][m] == 1)) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}