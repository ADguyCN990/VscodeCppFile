#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
ll n,m;
//保证没有自环，同一级别的入队次数只能为1
vector <ll> mp[MAXN];
ll indgr[MAXN];
int flag=0;
vector <int> ans;
void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u].emplace_back(v);
        indgr[v]++;
    }
}

void topp()
{
    queue <int> q;
    int cnt=0;//记录同一级别的人的个数，大于1就有多种排名情况
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]==0)
        {
            cnt++;
            q.push(i);
            ans.emplace_back(i);
        }
    }
    if(cnt>1) flag=1;
    while(!q.empty())
    {
        cnt=0;
        int now=q.front();q.pop();
        for(auto it:mp[now])
        {
            indgr[it]--;
            if(indgr[it]==0)
            {
                cnt++;
                ans.emplace_back(it);
                q.push(it);
            }
        }
        if(cnt>1) flag=1;
    }
}

void output()
{
    for(auto x:ans) cout<<x<<endl;
    cout<<flag;
}

void solve()
{
    cin>>n>>m;
    build();
    topp();
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}