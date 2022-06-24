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
ll V, M, n;
ll v[MAXN], m[MAXN], w[MAXN];
ll dp[25][85];
void solve() {
    V = read(), M = read(), n = read();
    for (int i = 1; i <= n; i++) {
        v[i] = read();
        m[i] = read();
        w[i] = read();
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = V; j >= 0; j--) 
            for (int k = M; k >= 0; k--) 
                dp[j][k] = min(dp[j][k], dp[max(0ll, j - v[i])][max(0ll, k - m[i])] + w[i]);    
    printf("%lld\n", dp[V][M]);
}

int main() {
    solve();
    return 0;
}