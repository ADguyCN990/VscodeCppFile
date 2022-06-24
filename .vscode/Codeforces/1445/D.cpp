#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 400005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define mod 998244353
ll n;ll a[MAXN];
ll quickpow(ll a,ll n)
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

ll c(ll n,ll m)
{
    if(m==0) return 1;
    if(m>n-m) m=n-m;
    ll up=1;ll down=1;
    for(int i=1;i<=m;i++)
    {
        up=(up*(n-i+1))%mod;
        down=(down*i)%mod;
    }
    return up*quickpow(down,mod-2)%mod;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
    ll ans=0;
    sort(a+1,a+1+2*n);
    for(int i=1;i<=n;i++)
        ans-=a[i];
    for(int i=n+1;i<=n*2;i++)
        ans+=a[i];
    cout<<(ans%mod*c(2*n,n)%mod)%mod<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // cin>>T;
    // while(T--)
    // {
        solve();
    //}

    return 0;
}