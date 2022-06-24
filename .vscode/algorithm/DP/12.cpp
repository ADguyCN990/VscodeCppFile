#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
ll n, V;
ll dp[MAXN][MAXN];
ll v[MAXN], w[MAXN];
int path[MAXN], cnt = 0; //保存路径

void dfs(int i, ll j) {
    if (i == n + 1) return;
    if (j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]) {
        path[++cnt] = i;
        dfs(i + 1, j - v[i]); //选择当前物品
    }
    else
        dfs(i + 1, j); //不选择当前物品
}

void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) v[i] = read(), w[i] = read();
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= V; j++) {
            dp[i][j] = dp[i + 1][j]; //状态复制
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }       
    printf("%lld\n", dp[1][V]); 
    // for (int i = 1, j = V; i <= n; i++) {
    //     if (j >= v[i] && dp[i + 1][j - v[i]] + w[i] == dp[i][j]) {
    //         //选了当前的物品，把他扔掉
    //         path[++cnt] = i;
    //         j -= v[i];
    //     }
    // }       
    dfs(1, V);
    for (int i = 1; i <= cnt; i++) printf("%d ", path[i]);
}

int main() {
    solve();
    return 0;
}