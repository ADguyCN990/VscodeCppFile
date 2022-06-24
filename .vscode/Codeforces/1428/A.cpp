#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,xx,y,yy;

void solve()
{
    cin>>x>>y>>xx>>yy;
    ll cnt=(x!=xx)+(y!=yy);
    if(cnt==1) cnt=0;
    cout<<abs(x-xx)+abs(y-yy)+cnt<<endl;
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