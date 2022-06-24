#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll a[MAXN];ll b[MAXN];
ll t,n;
void solve()
{
    //用总的方案数减去非法的方案数（至少两个ai相同并且至少两个bi相同）
    cin>>n;
    map<int,ll> cnt_a;//ai=x的个数
    map<int,ll> cnt_b;//bi=y的个数
    map<ll,vector<int>> mp;//bi对应的ai
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>b[i];
        cnt_a[a[i]]++;cnt_b[b[i]]++;mp[b[i]].emplace_back(a[i]);

    }
    ll sum_all=n*(n-1)*(n-2)/6;//总的方案数
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll tmp=0;
        for(auto i:mp[i]) tmp+=(cnt_a[i]-1);
        ans+=(cnt_b[i]-1)*tmp;
    }
    cout<<sum_all-ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}