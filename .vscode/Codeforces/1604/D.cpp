#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll x,y;
void solve()
{
    cin>>x>>y;
    if(x>y)
    {
        cout<<x+y<<endl;
        return;
    }
    else if(x==y)
    {
        cout<<x<<endl;
        return;
    }
    else if(x<y)
    {
        cout<<y-(y%x)/2<<endl;
        return;
    }
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