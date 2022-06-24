#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
ll n;
ll a[15][15];
ll dp[15][15][30]; //横纵坐标为k=i+j时的最大值

bool check(int x, int y) {
    //是否非法
    if (x < 1 || x > n || y < 1 || y > n) return true;
    return false;
}

void solve() {
    n = read();
    while (1) {
        int u = read(), v = read(), w = read();
        if (!u && !v && !w) break;
        a[u][v] = w;
    }
    dp[1][1][2] = 0;
    //目标：dp[n][n][2n]
    for (int k = 3; k <= 2 * n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int ax = i, ay = k - i, bx = j, by = k - j;
                if (check(ax, ay) || check(bx, by)) continue;
                ll w1 = dp[ax - 1][bx - 1][k - 1], w2 = dp[ax][bx - 1][k - 1];
                ll w3 = dp[ax - 1][bx][k - 1],  w4 = dp[ax][bx][k - 1];
                ll w = max(max(w1, w2), max(w3, w4));
                if (ax == bx) 
                    //两个点是同一个点
                    dp[i][j][k] = max(dp[i][j][k], w + a[ax][ay]);
                else 
                    //两个点不是同一个点
                    dp[i][j][k] = max(dp[i][j][k], w + a[ax][ay] + a[bx][by]);
            }
        }
    }
    printf("%lld\n", dp[n][n][2 * n]);
}

int main() {
    solve();
    return 0;
}