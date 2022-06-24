#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;

void solve()
{
    cin>>n>>k;
    n--;
    if(n==0)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    ll add=1;
    while(n>0&&add<=k)
    {
        n=max(0ll,n-add);
        add*=2;
        ans++;
    }
    if(n<=0) 
    {
        cout<<ans<<endl;
        return;
    }
    ans+=(n-1)/k+1;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}