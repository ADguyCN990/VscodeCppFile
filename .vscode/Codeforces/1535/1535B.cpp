#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll a[MAXN];
ll t,n;
vector <ll> v;
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    while(b)
    {
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        v.clear();
        ll cnt_odd=0;
        ll cnt_even=0;
        ll ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(a[i]%2==1) 
            {
                cnt_odd++;
                v.push_back(a[i]);
            }
            else cnt_even++;
        }
        for(ll i=0;i<cnt_odd-1;i++)
        {
            for(ll j=i+1;j<cnt_odd;j++)
            {
                if(gcd(v[i],v[j])>1) ans++;
            }
        }        
        ans+=(cnt_even-1)*cnt_even/2;
        ans+=cnt_even*cnt_odd;
        cout<<ans<<endl;
    }
    
    return 0;
}