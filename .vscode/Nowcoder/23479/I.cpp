#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f3f3f3f3f
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
ll n, k;
ll a[MAXN], b[MAXN];
ll v[MAXN], w[MAXN];
ll dp[1005][1005]; //选了前i个数，余数为j时的最大能量
void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), b[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        v[i] = a[i] % k;
        w[i] = b[i];
    }
    memset(dp, -INF, sizeof dp);
    dp[0][0]= 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j < k; j ++)
            dp[i][j] = dp[i - 1][j];
        for (int j = 0; j < k; j ++)
        {
            if (j < v[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j + k - v[i]] + w[i]);
            else
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    // for (int i = 1; i <= n; i ++)
    // {
    //     printf("i= %d:\n", i);
    //     for (int j = 0; j < k ; j ++)
    //         printf("%lld ", dp[i][j]);
    //     puts("");
    // }
    ll ans = dp[n][0];
    if (!ans)
        puts("-1");
    else
        printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}