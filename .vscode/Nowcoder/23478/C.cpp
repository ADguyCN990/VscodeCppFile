#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
#define MAXM 200005
#define mod 1000000007
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
ll dp[MAXN]; //体积为i时的方案数
ll ans[MAXN]; //体积为i的西瓜数量
int idx;
int n;
void solve()
{
    dp[0] = 1;
    n = read(); //体积上限
    for (int i = 1; i <= n; i ++) dp[i] = read();
    for (int i = 1; i <= n; i ++) //半个瓜的重量
    {
        while (dp[i])
        {
            ans[++ idx] = i << 1;
            for (int j = 1; j <= n; j ++)
            {
                if (j >= i)
                    dp[j] = (dp[j] + mod - dp[j - i]) % mod; //清除当前半个瓜的影响
                if (j >= i + i)
                    dp[j] = (dp[j] + mod - dp[j - i - i]) % mod; //清除当前整个瓜的影响
            }
        }
    }
    printf("%d\n", idx);
    for (int i = 1; i <= idx; i ++) printf("%d ", ans[i]);
}

int main()
{
    solve();
    return 0;
}