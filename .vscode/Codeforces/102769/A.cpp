#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}

void solve()
{
    ll a,b;
    cin>>a>>b;
    ll n=a+b;
    cout<<a*(a-1)/gcd(a*(a-1),n*(n-1))<<"/"<<n*(n-1)/gcd(a*(a-1),n*(n-1))<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}