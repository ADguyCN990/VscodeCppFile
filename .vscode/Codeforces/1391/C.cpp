#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
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
ll n;
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a) % mod;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a) % mod;
        }
    }
    return ans;
}
void solve()
{
    n = read();
    ll base = 1;
    if (n == 1)
    {
        puts("0");
        return;
    }
    for (ll i = 2; i <= n; i ++)
    {
        base = base * i % mod;
    }
    printf("%lld\n", (base + mod - quickpow(2, n - 1)) % mod);
}

int main()
{
    solve();
    return 0;
}