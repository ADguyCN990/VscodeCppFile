#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];
//使最小的数变得尽可能大
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[1]<<endl;
        return;
    }
    sort(a+1,a+1+n);
    ll dx=a[1];
    for(int i=1;i<n;i++)
    {
        dx=max(dx,a[i+1]-a[i]);
    }
    cout<<dx<<endl;
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