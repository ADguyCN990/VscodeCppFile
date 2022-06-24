#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 50005
#define mod 998244353
ll n,m;
ll a[MAXN];
vector <int> v;//记录次数
int vis[MAXN];//判重
int p[MAXN];//指数
ll fac[MAXN],f[MAXN];
ll quickpow (ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            n--;
            ans=(ans*a)%mod ;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a)%mod ;
        }
    }
    return ans;
}

ll dive(ll x) {return quickpow(x,mod-2);}

void pre()
{
    fac[0]=1;
    for(int i=1;i<=50000;i++) fac[i]=fac[i-1]*i%mod;
    f[50000]=dive(fac[50000]);
    for(int i=49999;i>=0;i--)
    {
        f[i]=f[i+1]*(i+1)%mod;
    }
}

ll C(ll n,ll m)
{
    if(m>n) return 0;
    return fac[n]*f[m]%mod*f[n-m]%mod;
}

void solve()
{
    pre();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        p[a[i]]++;
        if(vis[a[i]]) continue;
        vis[a[i]]=1;
        v.emplace_back(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        ll ans=1;
        for(auto x : v)
        {
            ans=ans*quickpow(C(i,x),p[x])%mod;
        }
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}