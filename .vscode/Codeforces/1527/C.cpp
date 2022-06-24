#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];
ll dp[MAXN];
map<ll,ll> cnt;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[i]=0;
    cnt.clear();
    int i=1;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(cnt.count(a[i]))
        {
            dp[i]+=cnt[a[i]];//他能做出的贡献
        }
        cnt[a[i]]+=(i);//更新，对于下一个a[i]出现时，能多出[1,i]的贡献
    }
    for(int i=1;i<=n;i++) ans+=dp[i];
    cout<<ans<<endl;
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