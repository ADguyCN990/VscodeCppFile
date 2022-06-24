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
int n, m;
vector<int> g[MAXN][30];
int dis[MAXN][MAXN]; //1到i且n到j且回文
bool vis[MAXN][MAXN];

struct node {
    int x, y, val;
    bool operator < (const node &a) const {
        return val > a.val;
    }
};

void dij() {
    memset(dis, 0x3f, sizeof dis);
    dis[1][n] = 0;
    priority_queue<node> q;
    q.push({1, n, 0});
    while (q.size()) {
        node now = q.top();
        q.pop();
        if (vis[now.x][now.y]) continue;
        vis[now.x][now.y] = true;
        int nowx = now.x, nowy = now.y;
        for (int k = 0; k < 26; k++) {
            for (int tox : g[nowx][k]) {
                for (int toy: g[nowy][k]) {
                    if (dis[tox][toy] > dis[nowx][nowy] + 2) {
                        dis[tox][toy] = dis[nowx][nowy] + 2;
                        q.push({tox, toy, dis[tox][toy]});
                    }
                }
            }
        }
    }
}

char opt[5];

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        scanf("%s", opt);
        int num = (int)(opt[0] - 'a');
        g[u][num].pb(v);
        g[v][num].pb(u);
    }
    dij();
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, dis[i][i]); //奇数个节点偶数条边
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 26; k++) {
            for (int j : g[i][k]) {
                ans = min(ans, dis[i][j] + 1); //偶数个节点奇数条边
            }
        }
    }
    if (ans == INF) {
        puts("-1");
        return;
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}