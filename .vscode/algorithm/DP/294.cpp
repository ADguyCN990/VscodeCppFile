#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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

char s[105][15];
int a[105];
int n, m;
vector<int> v;
vector<int> g[(1 << 10) + 5];
int cnt[(1 << 10) + 5];
ll dp[2][(1 << 10) + 5][(1 << 10) + 5];
bool judge(int st) {
    if (st & (st >> 1) || st & (st >> 2)) return false;
    if (st & (st << 1) || st & (st << 2)) return false;
    return true; 
}

bool work(int now, int pre) {
    if (now & pre) return false;
    return true;
}

int sum(int st) {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u = st >> i & 1;
        ans += u;
    }
    return ans;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i]);
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'P') //山地
                {}
            else //平原
                ans += (1 << j);
        }
        a[i] = ans;
    }
    for (int st = 0; st < (1 << m); st++) 
        if (judge(st)) 
            v.pb(st), cnt[st] = sum(st);
    for (int now : v) 
        for (int pre : v)
            if (work(now, pre))
                g[now].pb(pre);
    for (int i = 1; i <= n; i++) 
        for (int now : v) 
            for (int PRE : g[now]) {
                dp[i & 1][now][PRE] = 0; //清空滚动数组之前的结果
                if (work(now, a[i])) //当前行合法
                    for (int pre : g[PRE]) //枚举上上行
                        if (work(now, pre)) //若上上行和当前和不会互相攻击
                            dp[i & 1][now][PRE] = max(dp[i & 1][now][PRE], dp[(i - 1) & 1][PRE][pre] + cnt[now]);
            }          
    ll ans = 0;
    for (int now : v) 
        for (int pre : g[now]) 
            ans = max(ans, dp[n & 1][now][pre]);   
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}