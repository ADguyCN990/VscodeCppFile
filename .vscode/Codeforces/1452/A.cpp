#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<2*a<<endl;
        return;
    }
    if(a<b) swap(a,b);

    cout<<max(0,(a-b-1)*2)+b*2+1<<endl;
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