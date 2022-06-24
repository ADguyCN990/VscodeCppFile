#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define mod 998244353
ll n;
ll a[MAXN];
ll b[MAXN];//除去剑头
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    a[0]=1;b[0]=1;
    a[1]=0;b[1]=0;
    a[2]=0;b[2]=1;
    for(int i=3;i<=n;i++)
    {
        a[i]=b[i-3]*2%mod;
        b[i]=(b[i-2]+a[i])%mod;
    }
    cout<<b[n-2];
    return 0;
}