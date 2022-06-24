#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define MXBIT (1 << 16) + 10
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

bool judge(ll x) { //判断行上的状态是否合法
    if (x & (x << 1))
        return false;
    if (x & (x >> 1))
        return false;
    return true;
}

bool check(ll x, ll y) { //判断当前行和上一行的关系是否合法
    if (x & y) return false;
    if (x & (y << 1)) return false;
    if (x & (y >> 1)) return false;
    return true;
}

ll a[20][20];
int dp[20][MXBIT];  //第i行的第j个合法状态对应的全局解
int pre[20][MXBIT]; //第i行第j个合法状态
int n;

void init() {
    memset(dp, 0, sizeof dp);
    memset(pre, 0, sizeof dp);
}

void solve() {
    n = read();
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = read();
    int tot = (1 << n);
    vector<int> v;
    for (int i = 0; i < tot; i++) {
        if (judge(i)) 
            v.pb(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v.size(); j++) {
            int t = v[j];
            for (int k = 0; k < n; k++) {
                if (t >> k & 1) pre[i][j] += a[i][k];
            }
        }
    }
    //第一行没有上一行，直接由预处理的单个的一行复制上去
    for (int i = 0; i < v.size(); i++) dp[1][i] = pre[1][i];

    for (int i = 2; i <= n; i++) { //行数
        for (int j = 0; j < v.size(); j++) { //当前行的某个合法状态
            for (int k = 0; k < v.size(); k++) { //上一行的某个合法状态
                if (check(v[j], v[k])) { //满足限制条件
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + pre[i][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}