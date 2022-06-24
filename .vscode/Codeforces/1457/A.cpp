#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,r,c;
ll get(ll x,ll y)
{
    return abs(r-x)+abs(c-y);
}

void solve()
{
    cin>>n>>m>>r>>c;
    ll ans=max({get(1,m),get(n,m),get(n,1),get(1,1)});
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