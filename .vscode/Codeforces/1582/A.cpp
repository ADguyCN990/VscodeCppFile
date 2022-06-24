#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c;

void solve()
{
    cin>>a>>b>>c;
    
    cout<<(a+c)%2<<endl;
    
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