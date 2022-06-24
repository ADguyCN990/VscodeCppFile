#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
ll n, V;
ll b[MAXN], v[MAXN];
ll w[MAXN];
ll dis[MAXN]; //根据题述操作从1变换到i需要的最少步数
ll dp[MAXN][MAXN * 12];
void prebfs()
{
    for (int i = 2; i <= 1000; i ++) dis[i] = INF;
    dis[1] = 0;
    for (int i = 1; i <= 1000; i ++)
    {
        for (int j = 1; j <= i; j ++)
        {
            int tmp = i + i / j;
            if (tmp <= 1000) dis[tmp] = min(dis[tmp], dis[i] + 1);
        }
    }
}

void solve()
{
    n = read(), V = read();
    ll tmp = 0;
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++) b[i] = read(), v[i] = dis[b[i]], tmp += v[i];
    for (int i = 1; i <= n; i ++) w[i] = read();
    // 01背包，n件物品，总体积为V，单件体积为dis[b[i]]，单件价值为w[i]，求最大价值
    if (V >= tmp)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i ++) ans += w[i];
        printf("%lld\n", ans);
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= V; j ++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i - 1][j - v[i]] + w[i], dp[i][j]);
        }
    }
    printf("%lld\n", dp[n][V]);
}

int main()
{
    prebfs();
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}