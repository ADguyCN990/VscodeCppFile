#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[65];
ll pre[65];
int t,n;
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
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

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[1]=6;
    ll temp=1;
    for(ll i=0;i<=60;i++)
    {
        pre[i]=temp;
        temp*=2;
    }
    for(int i=2;i<=60;i++)
    {
        dp[i]=(dp[i-1]%mod*quickpow(4,pre[i-1])%mod)%mod;
        //cout<<dp[i]<<endl;
    }
    
    cin>>n;
    cout<<dp[n]<<endl;
    
    return 0;
}