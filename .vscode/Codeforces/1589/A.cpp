#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll u,v;
    cin>>u>>v;
    cout<<-u*u<<" "<<v*v<<endl;
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