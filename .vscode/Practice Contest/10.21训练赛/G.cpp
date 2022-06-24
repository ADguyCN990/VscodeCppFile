#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll n,k,sum,a,b;
ll ans[MAXN];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;
        sum+=temp;
    }
    a=sum/n;b=sum%n;
    for(int i=1;i<=k;i++)
    {
        b*=10;
        ans[i]=b/n;
        b=b%n;
    }
    cout<<a<<".";
    for(int i=1;i<=k;i++) cout<<ans[i];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}