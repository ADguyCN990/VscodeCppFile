#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXN];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}

int n, m, t;
int color[MAXN], c[MAXN];

void dfs(int now, int fa) {
    if (now == t) //依然能回到t
        return;
    if (c[now] == -1) //第一次到达某个点
        c[now] = fa;
    else if (color[now] == -1) { //第二次到达某个点
        if (c[now] == fa) return;
        color[now] = fa; //被其他点染色了，更新
    }
    else //非法情况不用管
        return;
    for (int i = head[now]; i; i = edge[i].next)
        dfs(edge[i].to, fa);
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    t++;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u++, v++;
        add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        c[i] = -1;
        color[i] = -1;
    }
    for (int i = head[t]; i; i = edge[i].next) { //遍历特殊的邻点作为起点做dfs
        int to = edge[i].to;
        dfs(to, to);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (c[i] == i && color[i] == -1)
            ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i] - 1);
    puts("");
    return 0;
}