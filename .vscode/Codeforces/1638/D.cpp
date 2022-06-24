#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 1005
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
int n, m;
int a[MAXN][MAXN]; //用-1表示修改的状态
bool vis[MAXN][MAXN];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct node {
    int x, y, k;
};

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    vector<node> ans;
    queue<pii> q;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            vector<int> tmp = {a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1]};
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            if (count(tmp.begin(), tmp.end(), -1) + 1 != tmp.size()) 
                continue;
            ans.pb(i, j, tmp.back());
            q.emplace(i, j);
            vis[i][j] = true;
            a[i][j] = a[i + 1][j] = a[i][j + 1] = a[i + 1][j + 1] = -1;
        }
    }
    while (q.size()) {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        vis[xx][yy] = false;
        for (int i = 0; i < 8; i++) {
            int x = xx + dx[i], y = yy + dy[i];
            if (x >= n || x <= 0 || y >= m || y <= 0 || vis[x][y])
                continue;
            vector<int> tmp = {a[x][y], a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]};
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            if (count(tmp.begin(), tmp.end(), -1) + 1 == tmp.size()) {
                ans.pb(x, y, tmp.back());
                q.emplace(x, y);
                vis[x][y] = true;
                a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = -1;
            }
        }
    }
    bool flag = true;
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == -1)
                tmp++;
        if (tmp != m) {  
            puts("-1");
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%d %d %d\n", it.x, it.y, it.k);
    }
}

int main() {
    solve();
    return 0;
}