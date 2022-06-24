#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 4005
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
ll n;
ll tmp[MAXN];
ll a[MAXN], idx;
int dp[MAXN];
void solve()
{
    n = read();

    for (int i = 1; i <= 2 * n; i ++) tmp[i] = read();
    idx = 0;
    ll sum = 1, mx = tmp[1], mxpos = 1;
    for (int i = 2; i <= 2 * n; i ++)
    {
        if (tmp[i] >= mx)
        {
            mx = tmp[i];
            mxpos = i;
            a[++ idx] = sum;
            sum = 1;
        }
        else
            sum ++;    
    }
    if (sum) a[++ idx] = sum;
    // for (int i = 1; i <= idx; i ++) printf("%lld ", a[i]);
    // puts("");
    ll V = n;
    for (int i = 1; i <= V; i ++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= idx; i ++)
    {
        for (int j = V; j >= a[i]; j --)
        {
            dp[j] = max(dp[j], dp[j - a[i]]);
        }
    }
    if (dp[V]) puts("YES");
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