#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MAXM 2005
#define ll long long
#define INF 0x3f3f3f3f
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
int dp[3][MAXN];
int n;
//0表示被父亲灭火，此时儿子要么自己灭火，要么被其儿子灭火
//1表示被自己灭火，此时儿子可以被父亲自己和儿子灭火
//2表示被儿子灭火，则选出一个儿子，其余儿子要么自己灭火要么被其儿子灭火（如同状态0）

void dfs(int now, int pre) {
    dp[0][now] = 0, dp[1][now] = 1, dp[2][now] = INF;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        dp[0][now] += min(dp[1][to], dp[2][to]);
        dp[1][now] += min({dp[0][to], dp[1][to], dp[2][to]});
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dp[2][now] = min(dp[2][now], dp[0][now] - min(dp[1][to], dp[2][to]) + dp[1][to]);
    }
}

void solve() {
    n = read();
    for (int i = 2; i <= n; i++) {
        int j = read();
        add(i, j);
        add(j, i);
    }
    dfs(1, -1);
    printf("%d\n", min(dp[1][1], dp[2][1]));
}

int main() {
    solve();
}