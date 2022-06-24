#include<bits/stdc++.h>
using namespace std;
#define MAXN 25
int n, m;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int ans = 0;

int check(int x, int y) {
    //第x列和第y列
    int xx = 0, yy = 0;
    for (int i = 1; i <= n; i++)
        if (a[i][x] > a[i][y])
            xx++;
        else if (a[i][x] < a[i][y])
            yy++;
        else
            return 0;
    if (!xx || !yy) return 1;
    return 0;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &b[i][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int now = b[i][j];
            a[i][now] = m - j + 1;
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            ans += check(i, j);
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}