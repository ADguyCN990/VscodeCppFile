#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 2005
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
ll v[MAXN], w[MAXN], s[MAXN];
ll dp[MAXM];
void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        w[i] = read();
        s[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= s[i]; k *= 2) { //二进制枚举，分解成若干01背包
            ll tmpv = k * v[i];
            ll tmpw = k * w[i];
            for (int j = V; j >= tmpv; j--)
                dp[j] = max(dp[j - tmpv] + tmpw, dp[j]);
            s[i] -= k;
        }
        if (s[i]) { //最后的一部分，单独处理一下
            ll tmpv = s[i] * v[i];
            ll tmpw = s[i] * w[i];
            for (int j = V; j >= tmpv; j--)
                dp[j] = max(dp[j - tmpv] + tmpw, dp[j]);
        }
    }
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}