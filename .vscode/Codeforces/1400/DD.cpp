#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
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
int n;
int a[MAXN];
int pre[MAXN][MAXN]; //前i个数j出现的次数
int suf[MAXN][MAXN];
void solve()
{
    n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            pre[i][j] = 0, suf[i][j] = 0;
    for (int i = 1; i <= n; i ++) a[i] = read(), pre[i][a[i]] = 1, suf[i][a[i]] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            pre[i][j] += pre[i - 1][j];
    for (int i = n; i >= 1; i --)
        for (int j = 1; j <= n; j ++)
            suf[i][j] += suf[i + 1][j];
    for (int i = 2; i <= n - 2; i ++)
        for (int j = i + 1; j <= n - 1; j ++)
            ans += pre[i - 1][a[j]] * suf[j + 1][a[i]];
    printf("%lld\n", ans);
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