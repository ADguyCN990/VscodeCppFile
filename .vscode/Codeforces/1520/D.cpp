#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
#define MAXN 200005
ll a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]-=i;
    sort(a+1,a+1+n);
    ll ans=0;
    int i=1;
    while(i<=n)
    {
        ll cnt=upper_bound(a+1,a+1+n,a[i])-lower_bound(a+1,a+1+n,a[i]);
        ans+=(cnt-1)*cnt/2;
        i+=cnt;
    }
    cout<<ans<<endl;
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