#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
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
int head[MAXN];int tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add_edge(int from,int to) {
    edge[++tot].to = to; edge[tot].next = head[from]; head[from] = tot;
}
int n, m, k;
int depth[MAXN];
int fa[MAXN];
int mn = INF;
int start = 0;
void dfs(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        depth[to] = depth[now] + 1;
        dfs(to, now);
    }
}

void DFS(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        if (depth[to] != 0 && depth[now] - depth[to] + 1 < mn) { 
            //这条边连向了祖先节点,说明是个环。深度跨距表示环的长度，说明当前小于最小环
            if (depth[now] - depth[to] + 1 < 0) continue; //由于是无向边+树的遍历，这种情况是存在的
            mn = depth[now] - depth[to] + 1;
            start = now;
        }
        else if(!depth[to]) {
            fa[to] = now;
            depth[to] = depth[now] + 1;
            DFS(to, now);
        }
    }
}

void solve() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    depth[1] = 1;
    fa[1] = 0;
    if (m == n - 1) {
        puts("1");
        vector<int> odd, even; //深度按奇偶分类
        depth[1] = 1;
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            if (depth[i] & 1)
                odd.pb(i);
            else
                even.pb(i);
        }
        bool flag = odd.size() >= even.size();
        for (int i = 0; i < (k + 1) / 2; i++) {
            if (flag)
                printf("%d ", odd[i]);
            else
                printf("%d ", even[i]);
        }
        puts("");
        return;
    }
    DFS(1, 0);
    if (mn > k) {
        //环的长度大于k，跳着输出环中的编号
        puts("1");
        vector<int> pos;
        int now = start;
        for (int i = 1; i <= mn; i++) {
            if (i != 1 && now == start) 
                break;
            if (i & 1) 
                pos.pb(now);
            now = fa[now];
        }
        for (int i = 0; i < (k + 1) / 2; i++) 
            printf("%d ", pos[i]);
        puts("");
    }
    else {
        //直接输出环
        puts("2");
        printf("%d\n", mn);
        int now = start;
        for (int i = 1; i <= mn; i++) {
            printf("%d ", now);
            now = fa[now];
        }
        puts("");
    }

}

int main() {
    solve();
    return 0;
}