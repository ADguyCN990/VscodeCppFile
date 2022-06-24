#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n;
int a[MAXN];
int head[MAXN], tot;
int fa[MAXN];
int down[MAXN], dp[MAXN];
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}

void dfs_down(int now, int pre) {
    if (a[now]) down[now] = 1;
    else down[now] = -1;
    int ans = 0;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        fa[to] = now;
        dfs_down(to, now);
        ans += max(down[to], 0);
    }
    down[now] += ans;
}

void dfs_up(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        if (down[to] < 0 && dp[now] >= 0)
            dp[to] = down[to] + dp[now];
        else if (down[to] < 0 && dp[now] < 0)   
            dp[to] = down[to];
        else if (down[to] >= 0 && (dp[now] - down[to]) >= 0)
            dp[to] = dp[now];
        else if (down[to] >= 0 && (dp[now] - down[to]) < 0)
            dp[to] = down[to]; 
        dfs_up(to, now);
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v);
        add(v, u);
    }
    dfs_down(1, -1);
    // for (int i = 1; i <= n; i++) {
    //     printf("i: %d goal: %d\n", i, down[i]);
    // }
    dp[1] = down[1];
    dfs_up(1, -1);
    for (int i = 1; i <= n; i++)
        printf("%d ", dp[i]);
    return 0;
}