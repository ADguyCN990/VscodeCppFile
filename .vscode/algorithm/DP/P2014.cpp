#include<bits/stdc++.h>
using namespace std;
#define MAXN 305
#define MAXM 605
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
struct EDGE {
    int to, next;
}edge[MAXM];
int head[MAXN], tot;
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
int n, V;
int dp[MAXN][MAXN];
int w[MAXN];

void dfs(int now, int pre) {
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        for (int j = V; j >= 0; j--) //枚举体积 
            for (int k = 0; k <= j; k++)
                dp[now][j] = max(dp[now][j - k] + dp[to][k], dp[now][j]);
    }
    for (int j = V; j >= 1; j--)
        dp[now][j] = dp[now][j - 1] + w[now];
    dp[now][0] = 0;
}

void solve() {
    n = read(), V = read();
    V++;
    for (int i = 1; i <= n; i++) {
        int fa;
        fa = read(), w[i] = read();
        add(fa, i), add(i, fa);
    }
    dfs(0, -1);
    printf("%d\n", dp[0][V]);
}

int main() {
    solve();
    return 0;
}