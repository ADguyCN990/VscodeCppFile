#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
ll n, m, q;
char s[MAXN];
int g[MAXN][MAXN];
int dp[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m) continue;
        if (g[x][y] == g[a][b])
            return true;
    }
    return false;
}

void multySourceBFS() {
    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check(i, j))
                dp[i][j] = 1, q.emplace(i, j);
        }
    }
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (dp[a][b]) continue;
            dp[a][b] = dp[x][y] + 1;
            q.emplace(a, b);
        }
    }
}

void solve() {
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            g[i][j] = (int)(s[j] - '0');
        }
    }
    multySourceBFS();
    //一开始的时间定义为0
    while (q--) {
        ll x, y, t;
        x = read(), y = read(), t = read();
        if (!dp[x][y])
            printf("%d\n", g[x][y]);
        else if (t < dp[x][y])
            printf("%d\n", g[x][y]);
        else {
            //差奇数次，变；差偶数次，不变
            //dp[i][j]表示在第几轮迭代后该方格的值会发生变化
            int dif = t - dp[x][y];
            if (dif & 1)
                printf("%d\n", g[x][y]);
            else 
                printf("%d\n", g[x][y] ^ 1);
        }   
            

    }
}

int main() {
    solve();
    return 0;
}