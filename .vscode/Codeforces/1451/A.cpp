#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    if(n==1) cout<<0<<endl;
    else if(n==2) cout<<1<<endl;
    else if(n==3) cout<<2<<endl;
    else if(n%2==0) cout<<2<<endl;
    else if(n%2==1) cout<<3<<endl;
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