#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
#define MAXM 5000005
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
ll v[MAXN], w[MAXN];
ll dp[MAXM];
ll V, year, n;
void solve() {
    V = read(), year = read(), n = read();
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        w[i] = read();
    }
    for (int k = 1; k <= year; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = v[i]; j <= V; j++) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        V += dp[V];
    }
    printf("%lld\n", V);
}

int main() {
    solve();
    return 0;
}