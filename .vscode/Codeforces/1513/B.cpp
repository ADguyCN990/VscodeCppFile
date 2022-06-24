#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define mod 1000000007
#define ll long long
ll n;
ll a[MAXN];
ll get(ll n)
{
    ll ans=1;
    for(ll i=2;i<=n;i++) ans=(ans*i)%mod;
    return ans;
}

void solve()
{
    cin>>n;
    ll minx=0x3f3f3f3f;
    ll cnt=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        minx=min(a[i],minx);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==minx) cnt++;
        else
        {
            if((a[i]&minx)!=minx)
            {
                cout<<0<<endl;
                return;
            }
        }
    }
    cout<<(cnt)*(cnt-1)%mod*get(n-2)%mod<<endl;
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