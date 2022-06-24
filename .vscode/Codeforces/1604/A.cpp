#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n,k;
ll a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll temp=-1;
    for(int i=1;i<=n;i++)
    {
        temp=max(temp,a[i]-i);
    }
    cout<<temp<<endl;
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