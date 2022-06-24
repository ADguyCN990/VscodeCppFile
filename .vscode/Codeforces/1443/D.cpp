#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
ll n;
ll a[MAXN];
ll d[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        d[i]=a[i]-a[i-1];
    ll tmp=0;
    for(int i=2;i<=n;i++)
    {
        if(d[i]<0)
            tmp-=d[i];
    }
    if(tmp<=a[1])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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