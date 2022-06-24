#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ll long long
#define mod 80112002
ll n,m;
vector <int> mp[MAXN];
int indgr[MAXN];
int outdgr[MAXN];
ll dp[MAXN];
ll ans=0;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u].emplace_back(v);
        indgr[v]++;
        outdgr[u]++;
    }
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]==0)
        {
            dp[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto it:mp[now])
        {
            dp[it]=(dp[it]+dp[now])%mod;
            indgr[it]--;
            if(indgr[it]==0)
            {
                if(outdgr[it]==0) ans=(ans+dp[it])%mod;
                q.push(it);
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}