#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll h,p;
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==0)
        {
            a=a*a;
            n/=2;
        }
        else if(n%2==1)
        {
            ans=ans*a;
            n--;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {   
        cin>>h>>p;
        ll num=quickpow(2,h)-1;
        int result=(num%p==0?0:1);
        cout<<num/p+result<<endl;
    }
    return 0;
}