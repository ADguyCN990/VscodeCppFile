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
ll m, n;
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a) ;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a) ;
        }
    }
    return ans;
}
void solve()
{
    m = read(), n = read();
    if (m == 1)
    {
        if (n == 0) puts("1");
        else puts("2");
        return;
    }
    ll ans = 1ll << m;
    if (n == 0)
    {
        printf("%lld\n", ans);
        return;
    }
    printf("%lld\n", ans - 1);
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