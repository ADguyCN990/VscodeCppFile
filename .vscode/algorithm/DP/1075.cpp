#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 200005
#define INF 0x3f3f3f3f
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int head[MAXN], tot;
struct EDGE {
    int to, next, val;
}edge[MAXM];
void add(int from, int to, int val) {
    edge[++tot].to = to, edge[tot].val = val, edge[tot].next = head[from], head[from] = tot;
}
int n;
int down1[MAXN], down2[MAXN], up[MAXN];
int son1[MAXN], son2[MAXN];

void dfs_down(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) continue;
        dfs_down(to, now);
        if (down1[to] + val > down1[now]) {
            down2[now] = down1[now], son2[now] = son1[now];
            down1[now] = down1[to] + val, son1[now] = to;
        }
        else if (down1[to] + val > down2[now]) {
            down2[now] = down1[to] + val, son2[now] = to;
        }
    }
}

void dfs_up(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int val = edge[i].val;
        if (to == pre) continue;
        if (son1[now] == to) {
            up[to] = val + max(up[now], down2[now]);
        }
        else {
            up[to] = val + max(up[now], down1[now]);
        }
        dfs_up(to, now);
    }
}

void solve() {
    n = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, w);
    }
    dfs_down(1, -1);
    dfs_up(1, -1);
    int ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max(down1[i], up[i]));
    printf("%d\n", ans);
}

int main() {
    solve();
}