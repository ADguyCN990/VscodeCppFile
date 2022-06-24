#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
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
int n, m, k;
int x[MAXM], y[MAXM], xx[MAXM], yy[MAXM];
int d[MAXN][MAXN];

bool check(int mid) {
    memset(d, 0, sizeof d);
    d[1][1] = 1;
    d[1][m + 1] = -1;
    d[n + 1][1] = -1;
    d[n + 1][m + 1] = 1;
    for (int i = 1; i <= mid; i++) {
        d[x[i]][y[i]]--;
        d[x[i]][yy[i] + 1]++;
        d[xx[i] + 1][y[i]]++;
        d[xx[i] + 1][yy[i] + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] -= d[i - 1][j - 1] - d[i][j - 1] - d[i - 1][j];
            if (d[i][j] > 0) return false;
        }
    }
    return true;
}

void solve() {
    int ans = -1;
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; i++) {
        x[i] = read(), y[i] = read(), xx[i] = read(), yy[i] = read();
    }
    int l = 1, r = k;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}