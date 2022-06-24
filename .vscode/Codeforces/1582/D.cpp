#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n;
ll a[MAXN];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n%2==0)
    {
        for(int i=1;i<=n;i+=2)
        {
            cout<<-a[i+1]<<" "<<a[i]<<" ";
        }
        cout<<endl;return;
    }
    for(int i=1;i<=n-3;i+=2)
    {
        cout<<-a[i+1]<<" "<<a[i]<<" ";
    }
    ll x=a[n-2];ll y=a[n-1];ll z=a[n];
    if(x+y!=0)
    {      
        cout<<-z<<" "<<-z<<" "<<x+y<<endl;
        return;
    }
    else if(x+z!=0)
    {
        cout<<-y<<" "<<x+z<<" "<<-y<<endl;
        return;
    }
    else if(y+z!=0)
    {
        cout<<y+z<<" "<<-x<<" "<<-x<<endl;
        return;
    }
    
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