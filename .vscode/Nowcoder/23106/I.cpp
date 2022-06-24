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
#define mod 1000000007
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
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
ll n, m;

ll divi(ll a, ll b)
{
    return a * quickpow(b, mod - 2) % mod;
}

void solve()
{
    n = read(), m = read();
    ll a = m * (quickpow(2, n) - 2) % mod;
    ll b = quickpow(2, n);
    printf("%lld\n", divi(a, b));
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