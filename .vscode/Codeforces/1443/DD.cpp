#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 30005
ll n;
ll a[MAXN];
ll dp1[MAXN];//[1,i]的最小值
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp1[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(dp1[i-1]>a[i])
            dp1[i]=a[i];
        else
            dp1[i]=dp1[i-1];
    }
    ll dx=0;
    ll mn=0x3f3f3f3f;
    for(int i=n;i>=1;i--)
    {
        if(a[i]-dx<=mn)
            mn=a[i]-dx;
        else if(a[i]-dx-mn<=dp1[i]-dx)
            dx+=a[i]-dx-mn;
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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