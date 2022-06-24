#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define mod 998244353
ll dp[MAXN];
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2)
        {
            n--;
            ans=(ans*a)%mod;
        }
        else if(n%2==0)
        {
            n/=2;
            a=(a*a)%mod;
        }
    }
    return ans;
}

ll divide(ll a,ll b)
{
    return b*quickpow(a,mod-2)%mod;
}

void solve()
{
    //fn=f-1+f-3+f-5+...+2 or 1
    //f-3+f-5+...+2 or 1 = f-2
    //fn=f-1+f-2
    ll n;
    cin>>n;
    dp[1]=1;dp[2]=1;
    for(int i=3;i<=n;i++)
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    cout<<divide(quickpow(2,n),dp[n])<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    
    return 0;
}