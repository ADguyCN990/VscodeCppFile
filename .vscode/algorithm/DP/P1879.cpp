#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
#define MXBIT (1 << 12) + 10
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define mod 100000000
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
int a[MAXN][MAXN];
ll dp[MAXN][MXBIT];

bool judge(int row, int x) {
    //在第row行判断x这个状态是否正确
    for (int i = 0; i < m; i++) {
        if (a[row][i] == 0 && ((x >> (m - 1 - i) & 1) == 1))
            return false;
    }
    if (x & (x >> 1)) return false;
    if (x & (x << 1)) return false;
    return true;
}

bool check(int now, int pre) {
    if (now & pre) return false;
    return true;
}

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = read();
    int tot = 1 << m;
    vector<int> now;
    vector<int> pre;
    for (int i = 0; i < tot; i++) 
        if (judge(1, i))
            now.pb(i), dp[1][i]++;

    for (int i = 2; i <= n; i++) {
        pre = now;
        now.clear();
        for (int j = 0; j < tot; j++) 
            if (judge(i, j))
                now.pb(j);
        for (int j = 0; j < now.size(); j++) {
            int cur = now[j];
            for (int k = 0; k < pre.size(); k++) {
                int last = pre[k];
                if (check(cur, last))
                    dp[i][cur] = (dp[i][cur] + dp[i - 1][last]) % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < now.size(); i++)
        ans = (ans + dp[n][now[i]]) % mod;
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}