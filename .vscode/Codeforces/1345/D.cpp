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
char s[MAXN];
int g[MAXN][MAXN];
int id[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool check1() {
    //两个黑格中不能存在白格
    for (int x = 1; x <= n; x++) {
        int flag = 0; //0还未出现过黑格，1出现了黑格，2出现了白格，出现白格后又出现了黑格即为非法状态
        for (int y = 1; y <= m; y++) {
            if (g[x][y] && !flag)
                flag = 1;
            if (flag == 1 && !g[x][y])
                flag = 2;
            if (flag == 2 && g[x][y])
                return false;
        }
    }
    for (int y = 1; y <= m; y++) {
        int flag = 0;
        for (int x = 1; x <= n; x++) {
            if (g[x][y] && !flag)
                flag = 1;
            if (flag == 1 && !g[x][y])
                flag = 2;
            if (flag == 2 && g[x][y])
                return false; 
        }
    }
    return true;
}

bool check2() {
    //若存在全白行，一定存在全白列
    bool row = false, col = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) 
            cnt += g[i][j];
        if (!cnt) row = true; //存在全白行
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) 
            cnt += g[j][i];
        if (!cnt) col = true; //存在全白列
    }
    if (row && col || !row && !col) 
        return true;
    return false;
}

void bfs(int x, int y, int num) {
    queue<pii> q;
    id[x][y] = num;
    q.emplace(x, y);
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (id[a][b]) continue;
            if (!g[a][b]) continue;
            if (a < 1 || a > n || b < 1 || b > m) continue;
            id[a][b] = num;
            q.emplace(a, b);
        }
    }
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == '#')
                g[i][j] = 1;
            else 
                g[i][j] = 0;
        }
    }
    bool flag = check1();    
    if (!flag) {
        puts("-1");
        return;
    }
    flag = check2();
    if (!flag) {
        puts("-1");
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!id[i][j] && g[i][j])
                bfs(i, j, ++cnt);
    printf("%d\n", cnt);
}

int main() {
    solve();
    return 0;
}