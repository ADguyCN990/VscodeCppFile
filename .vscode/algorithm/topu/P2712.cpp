#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
vector <int> mp[MAXN];
int indgr[MAXN];//有些入度大于0的地方可能没有摄像头
int visit[MAXN];
ll n,m;

void build()
{
    for(int i=1;i<=n;i++)
    {
        int id;
        cin>>id>>m;
        visit[id]=1;
        while(m--)
        {
            int to;
            cin>>to;
            mp[id].emplace_back(to);
            indgr[to]++;
        }
    }
}

void topp()
{
    int del=0;
    queue <int> q;
    for(int i=1;i<=n;i++) if(indgr[i]==0&&visit[i]==1) 
    {
        q.push(i);
        del++;
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto it:mp[now])
        {
            indgr[it]--;
            if(indgr[it]==0&&visit[it]==1) 
            {
                q.push(it);
                del++;
            }
        }
    }
    if(del==n) cout<<"YES"<<endl;
    else cout<<n-del<<endl;
}

void solve()
{
    cin>>n;
    build();
    topp();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}