#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 2005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
typedef pair<int, int> pii;

struct point {
    int x, y;
}p[MAXN];

struct node {
    int val, d, id;
    bool operator< (const node &a) const {
        return val > a.val;
    }
};

int get(int i, int j) {
    int x = p[i].x, y = p[i].y;
    int xx = p[j].x, yy = p[j].y;
    return (ceil(sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy))));
}

int T, B, n;
int c[MAXN]; //各种交通方式每单位产生的CO2数量
vector<pair<int, pii>> e;
int w[MAXN][MAXN]; //距离
int dis[MAXN][MAXN]; //从源点到i，距离为j，消耗的最小二氧花坛数量
int v[MAXN][MAXN]; //从第i个点到第j个点汽车消耗的最小二氧化碳数量
bool vis[MAXN][MAXN];
int sx, sy, ex, ey;

void dij(int s) {
    priority_queue<node> q;
    //memset(dis, 0x3f, sizeof 0x3f);
    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= 2000; j++)
            dis[i][j] = INF;
    q.push(node{0, 0, 0});
    while (q.size()) {
        int now = q.top().id;
        int d = q.top().d;
        int VAL = q.top().val;
        q.pop();
        if (vis[now][d]) continue;
        vis[now][d] = true;
        for (int to = 0; to <= n + 1; to++) {
            int val = w[now][to];
            if (d + val > B) continue;
            //printf("now: %d to: %d pre: %d cur: %d\n", now, to, dis[to][d + val], VAL + v[now][to]);
            if (dis[to][d + val] > VAL + v[now][to]) {
                dis[to][d + val] = VAL + v[now][to];
                //printf("dis: %d\n", dis[to][d + val]);
                q.push(node{dis[to][d + val], d + val, to});
            }
        }
    }
}

int main() {
    sx = read(), sy = read();
    ex = read(), ey = read();
    B = read();
    c[0] = read();
    T = read();
    for (int i = 1; i <= T; i++) c[i] = read();
    n = read();
    p[0].x = sx, p[0].y = sy, p[n + 1].x = ex, p[n + 1].y = ey;
    for (int i = 1; i <= n; i++) {
        p[i].x = read(), p[i].y = read();
        int k = read();
        while (k--) {
            int j, val;
            j = read(), val = read();
            j++;
            e.push_back(make_pair(i, make_pair(j, val)));
        }
    }
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            w[i][j] = get(i, j);
    memset(v, 0x3f, sizeof v);
    v[0][n + 1] = c[0] * w[0][n + 1];
    for (int i = 1; i <= n; i++) {
        v[0][i] = c[0] * w[0][i];
        v[i][n + 1] = c[0] * w[i][n + 1];
    }
    //pair<i, pair<j, val>> 
    for (auto x : e) {
        int now = x.first, to = x.second.first, val = x.second.second;
        v[now][to] = v[to][now] = min(v[now][to], w[now][to] * c[val]);
    }
    dij(0);
    int ans = INF;
    for (int i = 0; i <= B; i++) {
        //printf("!!! %d\n", dis[n + 1][i]);
        ans = min(ans, dis[n + 1][i]);
    }
    if (ans == INF) puts("-1");
    else printf("%d\n", ans);
    return 0;
}

