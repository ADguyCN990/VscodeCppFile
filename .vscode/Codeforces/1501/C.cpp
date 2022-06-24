#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long 
ll n;
ll a[MAXN];
bitset <5000005> visit;//判断这个和之前有没有出现过
pair <int,int> ans[5000005];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int sum=a[i]+a[j];
            if(visit[sum]==0)
            {
                ans[sum]={i,j};
                visit[sum]=1;
            }
            else if(visit[sum]==1)
            {
                if(ans[sum].first!=i&&ans[sum].second!=j&&ans[sum].first!=j&&ans[sum].second!=i)
                {
                    cout<<"Yes"<<endl;
                    cout<<ans[sum].first<<" "<<ans[sum].second<<" "<<i<<" "<<j<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}