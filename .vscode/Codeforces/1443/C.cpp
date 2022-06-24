#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int a[MAXN];
int b[MAXN];
int n;

bool check(ll x)
{
    ll tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(x<a[i])
        tmp+=b[i];
    }
    return tmp<=x;
}

void solve()
{
    cin>>n;
    ll l=0;ll r=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        r+=b[i];
    }
    ll ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
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