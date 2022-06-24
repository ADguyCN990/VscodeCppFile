#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
ll a[MAXN];
ll n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll mx=-1;ll mn=0x3f3f3f3f;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            f=0;
            break;
        }
    }
    if(f)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    } 
    if(mx==a[1]&&mn==a[n]) cout<<3<<endl;
    else if(mx==a[n]||mn==a[1]) cout<<1<<endl;
    else cout<<2<<endl;

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