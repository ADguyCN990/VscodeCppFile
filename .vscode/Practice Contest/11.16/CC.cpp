#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int cnt[MAXN];
map <int,int> mp;//数据太大，数组维护不了，用map来判断在位置x上是否存在夹子
pii p[MAXN];
int n,m;
vector <int> ans;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].first>>p[i].second;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;mp[x]=1;
        for(int j=1;j<=n;j++)
        {
            if(x>=p[j].first&&x<=p[j].second)
            {
                cnt[j]++;
                if(cnt[j]>2)
                {
                    cout<<"impossible"<<'\n';
                    return;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(p[i].second==p[i+1].first)
        {
            if(cnt[i]<2&&cnt[i+1]<2&&!mp[p[i].second])
            {
                ans.emplace_back(p[i].second);
                cnt[i]++;cnt[i+1]++;mp[p[i].second]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=cnt[i];cnt[i]<=1;j++)
        {
            int pos=p[i].first+1;
            while(mp[pos])
                pos++;
            ans.emplace_back(pos);cnt[i]++;mp[pos]=1;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans)
        cout<<x<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}