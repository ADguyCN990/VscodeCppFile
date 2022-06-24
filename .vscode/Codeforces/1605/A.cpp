#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%3==0)
        cout<<0<<endl;
    else 
        cout<<1<<endl;
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