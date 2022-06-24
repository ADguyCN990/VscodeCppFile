#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll t,n;
ll a[MAXN];
map <ll,ll> mp;
void solve()
{
    cin>>n;
    ll sum=0;
    mp.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    if(sum*2ll%n!=0)
    {
        cout<<0<<endl;
        return;
    }
    ll goal=sum*2/n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>goal/2) break;
        ll temp=0;
        temp=mp[goal-a[i]];
        if(goal%2==0&&a[i]==goal/2)
        {
            temp=mp[a[i]]*(mp[a[i]]-1)/2;
            ans+=temp;
            break;
        }
        ans+=temp;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}