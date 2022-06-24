#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll mx=max({a,b,c});
    if(a==mx&&(b!=mx&&c!=mx)) cout<<0<<" ";
    else cout<<mx-a+1<<" ";
    if(b==mx&&(a!=mx&&c!=mx)) cout<<0<<" ";
    else cout<<mx-b+1<<" ";
    if(c==mx&&(a!=mx&&b!=mx)) cout<<0<<" ";
    else cout<<mx-c+1<<" ";
    cout<<endl;
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