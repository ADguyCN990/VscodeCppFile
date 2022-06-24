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
ll n, k;
ll a[MAXN];
ll mxpos, mx, mn;
void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    mx = -1e18, mn = 1e18, mxpos = 1;
    if (n == 1)
    {
        puts("0");
        return;
    }
    if (n == 2)
    {
        ll dx = max(a[1], a[2]) - min(a[1], a[2]);
        if (a[1] < a[2]) 
            a[1] = dx, a[2] = 0;
        else 
            a[1] = 0, a[2] = dx;
        if (k % 2 == 0) swap(a[1], a[2]);
        printf("%lld %lld\n", a[1], a[2]);
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
            mxpos = i;
        }
        if (a[i] < mn)
        {
            mn = a[i];
        }
    }
    if (mn < 0) for (int i = 1; i <= n; i ++) a[i] -= mn;
    if (mn < 0) mx -= mn;
    for (int i = 1; i <= n; i ++)
    {
        if ((k & 1) && i != mxpos) printf("%lld ", mx - a[i]);
        else if ((k & 1) && i == mxpos) printf("0 ");
        else if (i != mxpos) printf("%lld ", a[i]);
        else printf("%lld ", a[i]);
    }
    puts("");
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