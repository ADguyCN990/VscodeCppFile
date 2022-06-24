#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,cnt;
int path[MAXN];//预处理的dfs序
int f[MAXN],a[MAXN];//1表示多一个孩子，2表示死
int vis[MAXN];//1表示或者，0表示死了或者还没出生

vector <int> mp[MAXN];

void dfs(int rt,int pre)
{
    path[cnt++]=rt;
    if(!mp[rt].size()) return;
    for (auto it:mp[rt])
    {
        if(it==pre) continue;
        dfs(it,rt);
    }
    return;
}

void solve()
{
    cin>>n;
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i]>>a[i];
        if(f[i]==1)
            mp[a[i]].emplace_back(++cnt);
    }
    cnt=1;
    dfs(1,-1);
    // for(int i=1;i<=cnt;i++) cout<<path[i]<<" ";
    // cout<<endl;
    queue <int> q;
    q.push(1);
    vis[1]=1;
    for(int i=1;path[i];i++)
    {
        vis[path[i]]=1;
        q.push(path[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==2)
        {
            int now=a[i];//死了谁
            vis[now]=0;
            while(q.size()&&!vis[q.front()])
            {
                q.pop();
            }
            cout<<q.front()<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}