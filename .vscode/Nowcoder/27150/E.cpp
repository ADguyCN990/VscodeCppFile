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
ll dp[MAXN];
ll v[MAXN];
ll w[MAXN];
ll n, V;
void solve()
{
    dp[0] = 0;
    n = read(), V = read();
    for (int i = 1; i <= n; i ++) v[i] = read(), w[i] = read();
    for(int i = 1; i <= n; i ++)
    {
        for (int j = v[i]; j <= V; j ++)
        {
            dp[j] = max(dp[j-v[i]] + w[i], dp[j]);
        }
    }

    cout << dp[V] <<endl;
}

int main()
{
    solve();
    return 0;
}