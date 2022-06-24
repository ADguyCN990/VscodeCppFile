#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n,x;
#define mod 1000000007
vector <int> v;
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
            a=(a*a)%mod;
            n/=2;
        }
    }
    return ans;
}
void get(int n)
{
    while(n)
    {
        v.push_back(n%2);
        n/=2;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n>>x;
        get(x);
        ll ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
            ans=(ans+quickpow(n,i))%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}