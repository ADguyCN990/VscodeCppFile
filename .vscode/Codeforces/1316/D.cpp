#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int, int> pii;
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
pii a[MAXN][MAXN];
char ans[MAXN][MAXN];
queue<pii> q;

bool bfs() {
    while (q.size()) {
        pii cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        int ux = cur.first - 1, uy = cur.second;
        if (a[ux][uy] == a[x][y] && ans[ux][uy] == '?') {
            q.push({ux, uy});
            ans[ux][uy] = 'D';
        }
        int dx = cur.first + 1, dy = cur.second;
        if (a[dx][dy] == a[x][y] && ans[dx][dy] == '?') {
            q.push({dx, dy});
            ans[dx][dy] = 'U';
        }
        int lx = cur.first, ly = cur.second - 1;
        if (a[lx][ly] == a[x][y] && ans[lx][ly] == '?') {
            q.push({lx, ly});
            ans[lx][ly] = 'R';
        }
        int rx = cur.first, ry = cur.second + 1;
        if (a[rx][ry] == a[x][y] && ans[rx][ry] == '?') {
            q.push({rx, ry});
            ans[rx][ry] = 'L';
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++)
    //         printf("%c ", ans[i][j]);
    //     puts("");
    // }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (a[i][j].first != -1 && a[i][j].second != -1 && ans[i][j] == '?')
                return false;
    return true;
}

bool work(int nowx, int nowy, int tox, int toy, char now, char to) {
    if (a[nowx][nowy] == make_pair(-1, -1) && a[tox][toy] == make_pair(-1, -1)) {
        ans[nowx][nowy] = now;
        ans[tox][toy] = to;
        return true;        
    }
    return false;
}

int main() {
    vector<pii> cycle;
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[i][j] = '?';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j].first = read();
            a[i][j].second = read();
            if (a[i][j].first == i && a[i][j].second == j)
                ans[i][j] = 'X', q.push({i, j});
            else if (a[i][j].first == -1 && a[i][j].second == -1)
                cycle.push_back({i, j});
        }
    }
    if (!bfs()) {
        puts("INVALID");
        return 0;
    }
    int len = cycle.size();
    for (int i = 0; i < len; i++) {
        int x = cycle[i].first, y = cycle[i].second;
        if (ans[x][y] == '?') {
            bool flag = false;
            if (!flag)
                flag = work(x, y, x - 1, y, 'U', 'D');
            if (!flag)
                flag = work(x, y, x + 1, y, 'D', 'U');
            if (!flag)
                flag = work(x, y, x, y + 1, 'R', 'L');
            if (!flag)
                flag = work(x, y, x, y - 1, 'L', 'R');
            if (!flag) {
                puts("INVALID");
                return 0;
            }
        }
            
    }
    puts("VALID");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%c", ans[i][j]);
        puts("");
    }
    return 0;
}