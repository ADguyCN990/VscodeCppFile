#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
#define mod 998244353
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int rt(int x)
{
    int u = x % 9;
    if (u == 0) u = 9;
    return u;
}

int n;
int a[MAXN];
ll dp[MAXN][15]; //考虑了前𝑖个数，选择了一些数字使得求和对9取模得𝑗的方案数


void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), a[i] = rt(a[i]);
    for (int i = 1; i <= n; i ++)
    {
        int now = a[i];
        for (int j = 1; j <= 9; j ++)
        {
            int to = rt(now + j);
            // 当前位置上的数字为now，枚举1到9，对应能达到的状态就是 rt(now + j) 
            dp[i][to] = (dp[i - 1][to] + dp[i - 1][j]) % mod;
        }
        dp[i][now] ++; // 不要忘记单独的贡献
    }
    for (int i = 1; i <= 9; i ++) printf("%lld ", dp[n][i]);
}

int main()
{
    solve();
    return 0;
}