#include<bits/stdc++.h>
using namespace std;
#define MAXN 45
#define ll long long
ll n;
ll a[MAXN];
vector <ll> v;
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll temp;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve()
{
    cin>>n;
    v.clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-(a+1);
    if(n==1)
    {
        cout<<-1<<endl;
        return;
    }
    //cout<<n<<endl;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            v.emplace_back(a[j]-a[i]);
        }
    }
    ll ans=v[0];
    
    for(int i=1;i<v.size();i++)
    {
        ans=gcd(ans,v[i]);
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