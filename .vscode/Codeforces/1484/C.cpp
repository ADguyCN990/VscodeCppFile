#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,m,k;
vector <ll> v[MAXN];//统计某一天有空的朋友
ll ans[MAXN];
map <ll,ll> mp;//统计某个朋友的出现次数

void init()
{
    for(int i=0;i<=m;i++)
    {
        v[i].clear();
        ans[i]=0;
    }
    mp.clear();
}

void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int temp;
            cin>>temp;
            v[i].emplace_back(temp);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(v[i].size()==1)
        {
            int now=v[i][0];
            ans[i]=now;
            mp[now]++;
            if(mp[now]>(m+1)/2)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i++)
    {
        if(v[i].size()==1) continue;
        ll minx=0x3f3f3f3f;
        int minid=-1;
        for(int j=0;j<v[i].size();j++)
        {
            int now=v[i][j];
            if(mp[now]<minx)
            {
                minx=mp[now];
                minid=now;
            }
        }
        mp[minid]++;
        ans[i]=minid;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
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