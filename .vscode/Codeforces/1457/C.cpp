#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define INF 0x3f3f3f3f
ll n,p,k,x,y;
char s[MAXN];
ll dp[MAXN];//跳到i上的最小时间
void solve()
{
    cin>>n>>p>>k;//一开始落在p，每次跳k个单位
    scanf("%s",s+1);
    cin>>x>>y;
    ll ans=INF;
    for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=1;i<p;i++) dp[i]=INF;
    for(int i=p;i<=n;i++)
    {     
        dp[i]+=(i-p)*y;
        if(i>k)
            dp[i]=min(dp[i-k],dp[i]);
        dp[i]+=(s[i]=='0')*x;
    }
    // for(int i=1;i<=n;i++) 
    // {
    //     cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
    // }
    for(int i=n-k+1;i<=n;i++) ans=min(dp[i],ans);
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}