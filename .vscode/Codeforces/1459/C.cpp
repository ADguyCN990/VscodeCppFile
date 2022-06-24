#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,m;
ll a[MAXN];ll b[MAXN];

ll gcd(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    ll GCD=0;
    for(int i=2;i<=n;i++)
    {
        GCD=gcd(GCD,a[i]-a[i-1]);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<gcd(GCD,b[i]+a[1])<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}