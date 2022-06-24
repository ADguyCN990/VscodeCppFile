#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
#define MXBIT (1 << 10) + 10
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
int n, k;
ll dp[15][(1 << 10) + 10][105];
int cnt[(1 << 10) + 10]; //预处理每个合法状态中1的数量

bool judge(int x) { //判断是否是一个合法状态
    if (x & (x >> 1)) return false;
    if (x & (x << 1)) return false;
    return true;
}

bool check(int x, int y) { //判断与上一行的状态
    if (x & y) return false;
    if (x & (y >> 1)) return false;
    if (x & (y << 1)) return false;
    return true;
}

void solve() {
    n = read(), k = read();
    int tot = 1 << n;
    vector<int> v;
    for (int i = 0; i < tot; i++)
        if (judge(i))
            v.pb(i);
    for (int i = 0; i < v.size(); i++) {
        int num = 0;
        int t = v[i];
        for (int j = 0; j < n; j++) {
            if (t >> j & 1) 
                num++;
        }
        cnt[i] = num;
    }
    
    for (int i = 0; i < v.size(); i++) dp[1][i][cnt[i]]++;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < v.size(); j++) {
            int now = v[j];
            for (int l = 0; l < v.size(); l++) {
                int pre = v[l];
                if (check(now, pre)) {
                    for (int o = 0; o <= k; o++) {
                        if (o >= cnt[j])
                            dp[i][j][o] += dp[i - 1][l][o - cnt[j]];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += dp[n][i][k];
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}