#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
ll a[MAXN];ll b[MAXN];ll n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll sum_odd=0;ll sum_even=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) sum_odd+=a[i];
        else sum_even+=a[i];
    }
    if(sum_odd<sum_even)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2==1) cout<<1<<" ";
            else cout<<a[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2==0) cout<<1<<" ";
            else cout<<a[i]<<" ";
        }
    }
    cout<<endl;
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