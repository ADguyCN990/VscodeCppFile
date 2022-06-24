#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
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
ll n, k, l;
ll a[MAXN];
int dp[MAXN][20005]; //第j秒到达第i片海域是否合法
int pre[MAXN * 2];

void init()
{
    for (int i = 0; i <= k; i ++)
        pre[i] = i;
    for (int i = 1; i < k; i ++)
        pre[i + k] = k - i;
    for (int i = 0; i < k * 2; i ++) //起点
        dp[0][i] = 1;
}

void solve()
{
    n = read(), k = read(), l = read();
    //深度大于l被淹死，潮汐周期为2k
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++) a[i] = read();
    init();
    for (int i = 1; i <= n; i ++)
    {
        //dp[i][j] 由 dp[i - 1][j - 1] 或 dp[i][j - 1] 转移而来
        for (int j = i - 1; j < 2 * n * k; j ++)
        {
            if (j == 0)
            {   
                int h = a[i];
                if (l >= h) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else
            {
                int t = j % (2 * k);
                int h = a[i] + pre[t];
                if (l >= h)
                {
                    dp[i][j] = dp[i - 1][j - 1] | dp[i][j - 1];
                }
                else
                    dp[i][j] = 0;
            }
        }
    }
    bool flag = false;
    for (int i = n - 1; i <= 2 * k * n; i ++)
        if (dp[n][i])
            flag = true;
    if (flag) puts("YES");
    else puts("NO");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}