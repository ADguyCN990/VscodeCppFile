#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
#define mod 998244353
ll a[MAXN];
ll b[MAXN];ll c[MAXN];
ll n;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    b[0]=a[0];c[n-1]=a[n-1];
    for(int i=1;i<n;i++) b[i]=b[i-1]*a[i]%mod;
    for(int i=n-2;i>=0;i--) c[i]=c[i+1]*a[i]%mod;
    cout<<c[1]<<" ";
    if(n!=2)
    {
        for(int i=1;i<=n-2;i++)
        {
            cout<<b[i-1]*c[i+1]%mod<<" ";
        }
    }
    cout<<b[n-2];
    return 0;
}