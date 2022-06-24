#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==2)
    {
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    for(int i=2;i<=n;i++) ans+=abs(a[i]-a[i-1]);
    //cout<<"ans: "<<ans<<endl;
    ll mx=max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
    for(int i=2;i<n;i++)
    {
        if(a[i]>=a[i-1]&&a[i]<=a[i+1]||a[i]<=a[i-1]&&a[i]>=a[i+1]) continue;
        mx=max(mx,abs(a[i]-a[i-1])+abs(a[i]-a[i+1])-abs(a[i+1]-a[i-1]));
    }
    cout<<ans-mx<<endl;
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