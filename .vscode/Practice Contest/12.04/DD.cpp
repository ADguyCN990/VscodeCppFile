#include<bits/stdc++.h>
using namespace std;
double n,p1,p2,v1,v2;
double ans[5];
void solve()
{
    cin>>n>>p1>>p2>>v1>>v2;
    if(p1<p2)
    {
        swap(p1,p2);
        swap(v1,v2);
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