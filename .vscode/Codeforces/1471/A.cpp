#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll sum;
ll n,x;
void solve()
{
    ll n;
    cin>>n>>x;
    ll mx=0;ll mn=0;
    for(int i=1;i<=n;i++)
    {
        ll temp;cin>>temp;
        mn+=temp;
        mx+=(temp-1)/x+1;
    }
    mn=(mn-1)/x+1;
    cout<<mn<<" "<<mx<<endl;
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