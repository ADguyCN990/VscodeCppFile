#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
int a[MAXN];
vector <int> mp[MAXN];
int ans[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans[i]=INF;
    for(int i=1;i<=n;i++) mp[i].clear();
    for(int i=1;i<=n;i++)
    {
        mp[a[i]].emplace_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i].empty()) continue;
        int k=0;
        for(int j=1;j<mp[i].size();j++)
        {
            k=max(k,mp[i][j]-mp[i][j-1]);            
        }
        k=max(k,mp[i][0]);
        k=max(k,n-mp[i].back()+1);
       // cout<<"num: "<<i<<" k: "<<k<<endl;
        ans[k]=min(ans[k],i);
    }
    for(int i=2;i<=n;i++)
        ans[i]=min(ans[i],ans[i-1]);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==INF) cout<<-1<<" ";
        else cout<<ans[i]<<" ";
    }
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
