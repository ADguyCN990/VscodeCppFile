#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
    int to, next;
}edge[MAXM];
void add_edge(int from,int to) {
    edge[++tot].to = to; edge[tot].next = head[from]; head[from] = tot;
}
ll n, V;
ll v[MAXN], w[MAXN];
ll dp[MAXN][MAXN];
int root;

void dfs(int now, int pre) {
    //先枚举所有体积小于等于V-v[now]的所有子节点们能获得的最大价值
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (to == pre) continue;
        dfs(to, now); //用子节点更新父节点，树形DP，从下往上算
        for (int j = V - v[now]; j >= 0; j--) //所有子节点的体积和
            for (int k = 0; k <= j; k++) //当前子节点被分配到的体积
                dp[now][j] = max(dp[now][j], dp[now][j - k] + dp[to][k]);
    }
    //最后选上当前的根节点now物品
    for (int j = V; j >= v[now]; j--) dp[now][j] = dp[now][j - v[now]] + w[now];
    for (int j = 0; j < v[now]; j++) dp[now][j] = 0; //清空没选上now的所有状态
}

void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) {
        int fa;
        v[i] = read(), w[i] = read(), fa = read();
        if (fa == -1) root = i;
        else add_edge(fa, i), add_edge(i, fa);
    }
    dfs(root, -1);
    printf("%lld\n", dp[root][V]);
}

int main() {
    solve();
    return 0;
}