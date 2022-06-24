#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll b[MAXN];
ll ans[MAXN];
ll n;
vector <ll> mp[MAXN];
bool cmp(ll a,ll b){return a>b;}
void init()
{
    for(int i=0;i<=n;i++) mp[i].clear();
    for(int i=0;i<=n;i++) ans[i]=0;
}

void solve()
{
    init();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        ll goal;
        cin>>goal;
        mp[b[i]].emplace_back(goal);
    }
    for(ll i=1;i<=n;i++) 
    {
        sort(mp[i].begin(),mp[i].end(),cmp);
        for(int j=1;j<mp[i].size();j++)//[0,学校人数-1]
        {
            mp[i][j]=mp[i][j]+mp[i][j-1];//sort后进行前缀和处理
            //cout<<mp[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        int len=mp[i].size();
        for(int j=1;j<=len;j++)
        {
            ans[j]+=mp[i][len-1-len%j];
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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