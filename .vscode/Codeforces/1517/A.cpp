#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
void solve()
{
    cin>>n;
    ll ans=n/2050;
    if(ans==0||n%2050)
    {
        cout<<-1<<endl;
        return;
    }
    ll res=0;
    while(ans)
    {
        res+=ans%10;
        ans/=10;
    }
    cout<<res<<endl;
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