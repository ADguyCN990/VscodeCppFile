#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, int> pii;
#define MAXN 100005
#define MAXM 400005
#define INF 0x3f3f3f3f3f3f3f3f

int head[MAXN], tot;
struct EDGE {
    int to, next;
    ll val;
}edge[MAXM];
ll dis[25][MAXN]; //每个点到其若干个祖宗节点的最短距离
ll tmp_dis[MAXN];
int tmp_vis[MAXN];
int vis[MAXN];  
int n, m;

int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

void add(int from, int to, ll val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}

int getdep(int root, int x) { //求x是root的第几代儿子(0表示自己或者自己的父亲)
    if (root >= x) return 0; //x是root父亲或者祖先
    int pre = 0;
    while (x != root) {
        x >>= 1;
        pre++;
    }
    return pre;
}

void dij(int s) {
    //s为当前的根节点
    priority_queue<pii, vector<pii>, greater<pii>> q;
    tmp_dis[s] = 0;
    tmp_vis[s] = s; //没有其他意义，只是为了剪枝，因为要跑n遍dij，和下面三角不等式前一句组合等效于memset(dis, 0x3f)
    q.emplace(tmp_dis[s], s);
    while (q.size()) {
        int now = q.top().second;
        q.pop();
        if (vis[now] == s) continue;
        vis[now] = s;
        int dep = getdep(s, now);
        if (dep != 0) dis[dep][now] = tmp_dis[now];
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            ll val = edge[i].val;
            if (to <= s) continue; //是根节点的祖先，不用管
            if (tmp_vis[to] != s) {
                tmp_vis[to] = s;
                tmp_dis[to] = INF;
            }
            if (tmp_dis[to] > tmp_dis[now] + val) {
                tmp_dis[to] = tmp_dis[now] + val;
                q.emplace(tmp_dis[to], to);
            }
        }
    }
}

int lca(int a, int b) { //求最长公共前缀
    int ans = 0;
    while (a != b) {
        if (a > b) a >>= 1;
        else if (a < b) b >>= 1;
        ans++;
    }
    return a;
}

void build() {
    for (int i = 1; i <= n; i++) dis[0][i] = 0;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = INF;
    for (int i = 1; i <= n; i++)
        dij(i);
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    build(); //建二叉字典树
    int q = read();
    while (q--) {
        int x = read(), y = read();
        int fa = lca(x, y);
        ll ans = INF;
        int xdep = getdep(fa, x);
        int ydep = getdep(fa, y);
        while (fa > 0) { //枚举所有祖先
            ans = min(ans, dis[xdep][x] + dis[ydep][y]);
            xdep++, ydep++;
            fa >>= 1;
        }
        if (ans == INF) 
            puts("-1");
        else
            printf("%lld\n", ans);
    }
    
    return 0;
}