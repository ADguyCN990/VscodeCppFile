#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll R, G, B;
ll r[MAXN], g[MAXN], b[MAXN];
ll dp[MAXN][MAXN][MAXN];
void solve()
{
    R = read(), G = read(), B = read();
    for (int i = 1; i <= R; i ++) r[i] = read();
    for (int i = 1; i <= G; i ++) g[i] = read();
    for (int i = 1; i <= B; i ++) b[i] = read();
    sort(r + 1, r + 1 + R, greater<ll>());
    sort(g + 1, g + 1 + G, greater<ll>());
    sort(b + 1, b + 1 + B, greater<ll>());
    ll ans = 0;
    for (int i = 0; i <= R; i ++)
    {
        for (int j = 0; j <= G; j ++)
        {
            for (int k = 0; k <= B; k ++)
            {
                dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j + 1] * b[k + 1]);
                dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i + 1] * b[k + 1]);
                dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i + 1] * g[j + 1]);
                ans = max({dp[i][j + 1][k + 1], dp[i + 1][j][k + 1], dp[i + 1][j + 1][k], ans});
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}