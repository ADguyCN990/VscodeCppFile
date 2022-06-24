#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 50005
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
ll w[MAXN], v[MAXN];
ll dp[MAXM];
void solve() {
    n = read(), V = read();
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        w[i] = read();
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            if (j - v[i] <= 0)
                dp[j] = min(dp[0] + w[i], dp[j]);
            else
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}