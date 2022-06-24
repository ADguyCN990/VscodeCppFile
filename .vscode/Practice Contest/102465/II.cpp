#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int, int> pii;
int n, m;
int f[MAXN][MAXN];
char s[MAXN][MAXN];

void clr(int tx, int ty) {
    queue<pii> q;
    q.push({tx, ty});
    f[tx][ty] = 0;
    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (f[x + i][y + j]) {
                    q.push({x + i, y + j});
                    f[x + i][y + j] = 0;
                }
    }
}

void clr_sound() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] == 1) {
                f[i][j] = 0;
                int flag = 0;
                for (int ii = -1; ii <= 1; ii++)
                    for (int jj = -1; jj <= 1; jj++)
                        if (f[i + ii][j + jj])
                            flag = 1;
                if (flag)
                    f[i][j] = 1;
            }
}
int a, b, c;

void solve(int x, int y) {
    int dx = 1, dy = 1;
    while (f[x + dx][y + dx])
        dx++;
    for (int i = 1;; i++)
        if (!f[x][y + i]) {
            dy = i - dx * 2;
            break;
        }

    if (!f[x + dx * 2 + dy * 2][y + dx])
        a++;
    else if (f[x + dx][y + dx + dy])
        b++;
    else
        c++;
    clr(x, y);
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '#')
                f[i][j] = 1;
            else
                f[i][j] = 0;
        
    }
        
    
    clr(1, 1);
    clr_sound();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j])
                solve(i, j);

    printf("%d %d %d\n", a, b, c);
    return 0;
}
