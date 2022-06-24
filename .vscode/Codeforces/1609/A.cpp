#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20
int n;
ll a[MAXN];

int lowbit(int x) {return x&(-x);}

void solve()
{
    cin>>n;
    ll mx=0;
    int mxid=0;
    ll fac=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(a[i]%2==0)
        {
            a[i]/=2;
            fac++;
        }
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    cout<<mx*(1ll<<fac)+sum-mx<<endl;
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