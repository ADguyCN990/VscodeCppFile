#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
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
int n, m;
ll dp[2][105][(1 << MAXN) + 5];
int cnt[(1 << MAXN)];
vector<int> v; //存储当前行的合法状态
vector<int> g[(1 << MAXN) + 5]; //存储行与行之间的合法状态
bool judge(int st) { //行内判断合法状态
    if (st & st << 1) return false;
    if (st & st >> 1) return false;
    return true;
}

bool work(int now, int pre) { //行与行之间判断合法状态
    if (now & pre) return false;
    if (now & pre >> 1) return false;
    if (now & pre << 1) return false;
    return true;
}

int sum(int st) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = st >> i & 1;
        ans += u;
    }
    return ans;
}

void solve() {
    n = read(), m = read();
    vector<int> v;
    for (int st = 0; st < (1 << n); st++) 
        if (judge(st))
            v.pb(st), cnt[st] = sum(st);
    for (int now : v) 
        for (int pre : v)
            if (work(now, pre))
                g[now].pb(pre);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int k = 0; k <= m; k++) 
            for (int now : v) {
                dp[i & 1][k][now] = 0; //要先清空
                for (int pre : g[now]) 
                    if (cnt[now] <= k)
                        dp[i & 1][k][now] += dp[(i - 1) & 1][k - cnt[now]][pre];           
            }
    ll ans = 0;            
    for (int st : v) ans += dp[n & 1][m][st];
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}