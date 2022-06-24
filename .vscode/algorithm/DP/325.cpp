#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1505
#define MAXM 3005
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
int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[MAXM];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}
int dp[2][MAXN];
int d[MAXN];
int n;

void init() {
    tot = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
        d[i] = 0;
    }
    memset(dp, 0x3f, sizeof dp);
}

void dfs(int now, int pre) {
    dp[0][now] = 0, dp[1][now] = 1;
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now);
        dp[0][now] += dp[1][to];
        dp[1][now] += min(dp[0][to], dp[1][to]);
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        int u, k;
        scanf("%d:(%d)", &u, &k);
        u++;
        while (k--) {
            int v = read();
            v++;
            add(u, v);
            add(v, u);
            d[u]++, d[v]++;
        }
    }
    dfs(1, -1);
    printf("%d\n", min(dp[1][1], dp[0][1]));
}

int main() {
    while (scanf("%d", &n) != EOF) { 
        init();
        solve();
    }
    return 0;
}