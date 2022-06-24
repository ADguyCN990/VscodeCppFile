#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,c,d;

void solve()
{
    cin>>a>>b>>c>>d;
    cout<<max(a+b,c+d)<<endl;
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