#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
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
int head[MAXN];int tot;
struct EDGE {
    int to, next, val;
}edge[MAXM];
void add_edge(int from,int to,int val) {
    edge[++tot].to = to; edge[tot].val = val; edge[tot].next = head[from]; head[from] = tot;
}
int n, m; //n个节点m个叶子
ll dp[MAXN][MAXN]; //以i为根节点，选了j个观众的能赚到的最多的钱
ll pay[MAXN];
int siz[MAXN]; //统计以第i个节点为根的子树中有多少叶子节点

void pre(int now) {
    if (now > n - m) {
        siz[now] = 1;
        return;
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        pre(to);
        siz[now] += siz[to];
    }
}

void dfs(int now) {
    if (now > n - m) { //叶子节点
        dp[now][1] = pay[now];
        return;
    }
    int nowsize = 0;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        int tosize = siz[to];
        int val = edge[i].val;
        nowsize += tosize;
        dfs(to);
        for (int j = nowsize; j > 0; j--) {
            for (int k = 0; k <= min(tosize, j); k++) {
                dp[now][j] = max(dp[now][j], dp[now][j - k] + dp[to][k] - val);
            }
        }
    }
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n - m; i++) {
        int k = read();
        while (k--) {
            int to = read();
            int now = i;
            int val = read();
            add_edge(now, to, val);
        }
    }
    for (int i = n - m + 1; i <= n; i++) pay[i] = read();
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            dp[i][j] = -INF;
    pre(1); 
    dfs(1);
    ll ans = 0;
    for (int i = m; i >= 1; i--) {
        if (dp[1][i] >= 0) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}