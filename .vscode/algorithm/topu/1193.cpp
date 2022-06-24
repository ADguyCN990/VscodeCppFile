#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
vector <int> mp[MAXN];
int indgr[MAXN];
ll n;
vector <int> ans;

void topu()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
        if(indgr[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        ans.emplace_back(now);
        for(auto nxt:mp[now])
        {
            indgr[nxt]--;
            if(indgr[nxt]==0)
                q.push(nxt);
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int tmp;
            cin>>tmp;
            if(tmp==0) break;
            mp[i].emplace_back(tmp);
            indgr[tmp]++;
        }
    }
    topu();
    for(auto x:ans) cout<<x<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}