#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
map <ll,ll> mp;
void pre()
{
    ll ans=1;
    while(ans*ans<=1000000000)
    {
        mp[ans*ans]++;
        ans++;
    }
}

void solve()
{
    cin>>n;
    if(mp.count(n/2)&&n%2==0||mp.count(n/4)&&n%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    pre();
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}