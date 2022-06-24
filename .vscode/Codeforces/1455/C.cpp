#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,y;
void solve()
{
    cin>>x>>y;
    //x先手，发球和接球都要一点能量
    //赢球的一方要花费多一点的能量，并且下一次先手
    cout<<x-1<<" "<<y<<endl;
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