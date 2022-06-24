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
ll l[MAXN], r[MAXN], a[MAXN];
ll n;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        l[i] = read();
        r[i] = read();
        a[i] = read();
    }
    ll mn = INF, mx = -1;
    ll costl = INF, costr = INF, cost = INF;
    ll mxlen = -1;
    for (int i = 1; i <= n; i ++)
    {
        if (l[i] < mn)
            mn = l[i], costl = INF;
        if (l[i] == mn)
            costl = min(costl, a[i]);
        if (r[i] > mx)
            mx = r[i], costr = INF;
        if (r[i] == mx)
            costr = min(costr, a[i]);
        if (mxlen < r[i] - l[i] + 1)
            mxlen = r[i] - l[i] + 1, cost = INF;
        if (mxlen == r[i] - l[i] + 1)
            cost = min(cost, a[i]);
        ll ans = costl + costr;
        if (mxlen == mx - mn + 1)
            ans = min(ans, cost);
        printf("%lld\n", ans);
    }
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