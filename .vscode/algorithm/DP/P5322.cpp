#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 20005
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
ll s, n, V;
ll a[MAXN][MAXN];
ll dp[MAXM];
void solve() {
    s = read(), n = read(), V = read();
    for (int i = 1; i <= s; i++) 
        for (int j = 1; j <= n; j++)
            a[j][i] = read();
    for (int i = 1; i <= n; i++)
        sort(a[i] + 1, a[i] + 1 + s);
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j > a[i][k] * 2)
                    dp[j] = max(dp[j], dp[j - a[i][k] * 2 - 1] + k * i);
            }
        }
    }
    int ans = 0;
    printf("%lld\n", dp[V]);
}

int main() {
    solve();
    return 0;
}