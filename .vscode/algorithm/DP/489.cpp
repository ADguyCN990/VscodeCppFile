#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 65
#define MAXM 32005
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
ll V, n;
ll v[MAXN], w[MAXN];
bool isfa[MAXN]; //判断是否为主件
vector<int> g[MAXN];
ll dp[MAXM];

void init() {
    for (int i = 1; i <= n; i++) g[i].clear(), isfa[i] = false;
}

void work(int now, ll j) {
    int len = g[now].size(); //当前分组内的物品
    //类似于状态压缩的方法，因为数量不多，直接二进制遍历所有的状态，相当于枚举所有的方案
    for (int st = 0; st < (1 << len); st++) {
        int sum_v = v[now]; //主件必须选
        ll sum_w = w[now]; //主件必须选
        for (int i = 0; i < len; i++) {
            if (st >> i & 1) 
                sum_v += v[g[now][i]], sum_w += w[g[now][i]]; 
        }
        if (sum_v <= j)
            dp[j] = max(dp[j], dp[j - sum_v] + sum_w);
    }
}

void solve() {
    V = read(), n = read();
    init();
    for (int i = 1; i <= n; i++) {
        int fa;
        v[i] = read(), w[i] = read(), fa = read();
        w[i] = w[i] * v[i];
        if (fa) g[fa].pb(i);
        else isfa[i] = true;
    }
    for (int i = 1; i <= n; i++)
        if (isfa[i]) //枚举物品组
            for (int j = V; j >= v[i]; j--) //枚举分配给物品组的体积
                work(i, j);
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}