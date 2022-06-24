#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
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
int n, l, k, mx;
int d[MAXN];
int speed[MAXN];
int dp[MAXN][MAXN];

void solve()
{
    n = read(), l = read(), mx = read();
    for (int i = 1; i <= n; i ++) d[i] = read();
    for (int i = 1; i <= n; i ++) speed[i] = read();
    n ++;
    d[n] = l;

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 0; j <= mx; j ++)
        {
            dp[i][j] = dp[i - 1][j] + (d[i] - d[i - 1]) * speed[i - 1];
        }
        for (int j = i - 1; j >= 2; j --)
        {
            for (int k = 0; k <= mx; k ++)
            {
                if (k + i - j <= mx) dp[i][k + i - j] = min(dp[i][k + i - j], dp[j - 1][k] + (d[i] - d[j - 1]) * speed[j - 1]);
                else break;
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= mx; i ++) ans = min(ans, dp[n][i]);
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}