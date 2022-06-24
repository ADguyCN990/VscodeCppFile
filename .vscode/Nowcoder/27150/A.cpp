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
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll dp[MAXN];
ll a[MAXN];
ll n;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i] = read();
    }
    dp[1] = 0;
    for (int i = 2; i <= n;i ++)
    {
        for (int j = 1; j < i;j ++)
        {
            if (a[j] < a[i])
                dp[i] ++;
        }
    }
    for (int i = 1;i <= n; i ++) cout << dp[i] << " ";
}

int main()
{
    solve();
    return 0;
}