#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
int n, m;
// 选了i张牌，最多用了j次技能，差值为k（定义看下方）的最大w[i]之和，i用滚动优化
ll dp[2][MAXN][5505]; //定义差值为A的和减去B的和
ll v[MAXN], w[MAXN];
void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) w[i] = read(), v[i] = read();

    //体积之差加了2600，真实值应该减去2600
    for (int i = 0; i <= m; i ++) 
    {
        for (int j = 0; j <= 5200; j ++)
        {
            if (j == 2600) continue;
            dp[0][i][j] = -INF;
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= m; j ++)
        {
            for (int k = 0; k <= 5200; k ++)
            {
                int now = i & 1;
                int pre = now ^ 1;
                dp[now][j][k] = dp[pre][j][k]; //不放入任何牌堆
                
                if (k >= v[i]) //放入A牌堆并且不翻倍
                {
                    dp[now][j][k] = max(dp[now][j][k], dp[pre][j][k - v[i]] + w[i]);
                }

                if (k >= v[i] * 2 && j > 0) //放入A牌堆并且翻倍
                {
                    dp[now][j][k] = max(dp[now][j][k], dp[pre][j - 1][k - v[i] * 2] + w[i]);
                }

                if (k + v[i] <= 5200) //放入B牌堆并且不翻倍
                {
                    dp[now][j][k] = max(dp[now][j][k], dp[pre][j][k + v[i]] + w[i]);
                }
                
                if (k + 2 * v[i] <= 5200 && j > 0) //放入B牌堆并且翻倍
                {
                    dp[now][j][k] = max(dp[now][j][k], dp[pre][j - 1][k + v[i] * 2] + w[i]);
                }
            }
        }
    }

    printf("%lld\n", dp[n & 1][m][2600]);
}

int main()
{
    solve();
    return 0;
}