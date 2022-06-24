#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n, V;
ll dp[MAXN][5 * MAXN];
ll sum;
ll v[MAXN], w[MAXN], minv = INF;
void solve() {
    n = read(), sum = read();
    for (int i = 1; i <= n; i++) {
        v[i] = read(), w[i] = read();
        minv = min(minv, v[i]);
        V += v[i];
    }
    minv--;
    V -= minv * n;
    for (int i = 1; i <= n; i++) v[i] -= minv;
    for (int i = 1; i <= n; i++) 
        for (int j = V; j >= v[i]; j--)
            for (int k = i; k >= 1; k--)
                if (minv * k + j <= sum)
                    dp[k][j] = max(dp[k][j], dp[k - 1][j - v[i]] + w[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= V; j++)
            ans = max(ans, dp[i][j]);
    printf("%lld\n", ans);
    
}

int main() {
    solve();
    return 0;
}