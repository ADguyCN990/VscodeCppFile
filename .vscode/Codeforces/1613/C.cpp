#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int n;ll k;
int a[MAXN];

bool check(ll mid)
{
    ll cnt=0;
    for(int i=1;i<n;i++)
    {
        ll dx=a[i+1]-a[i];
        cnt+=min(mid,dx);
    }
    cnt+=mid;
    //cout<<"last for "<< mid<<" cause "<<cnt<<" damage"<<endl;
    return cnt>=k;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll l=1,r=k;
    ll ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))//毒性够了
        {
            ans=mid;
            r=mid-1;
        }
        else 
            l=mid+1;//毒性不够
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