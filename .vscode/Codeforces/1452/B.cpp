#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n;
ll a[MAXN];
void solve()
{
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    ll k=max(a[n],(sum+n-2)/(n-1));
    cout<<(n-1)*k-sum<<endl;    

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