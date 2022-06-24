#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 1000000007
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
int v[MAXN];
int n;
int V;
ll dp[MAXN][MAXN];

void solve()
{
    n = read(), V = read();
    for (int i = 1; i <= n; i ++) v[i] = read();
    for (int i = 0; i <= 1000; i ++) dp[i][0] = 1;
    // for (int i = 1; i <= V; i ++) printf("%lld ", dp[0][i]);
    // puts("");
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= V; j ++) dp[i][j] = dp[i - 1][j];
        for (int j = v[i] / 2; j <= V; j ++)
        {
            if (j >= v[i] && (j == v[i] || dp[i - 1][j - v[i]]) != 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i]]) % mod;

            if (j == v[i] / 2 || dp[i - 1][j - v[i] / 2] != 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i] / 2]) % mod;       
        }
        // for (int j = 1; j <= V; j ++) printf("%lld ", dp[i][j]);
        // puts("");
    }
    for (int i = 1; i <= V; i ++) printf("%lld ", dp[n][i]);
}

int main()
{
    solve();
    return 0;
}