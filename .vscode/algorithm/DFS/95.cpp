#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
int vis[MAXN];
int b[MAXN];
int n,m;

void dfs(int now,int pre)
{
    if(now>m)
    {
        for(int i=1;i<=m;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=pre+1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            b[now]=i;
            dfs(now+1,i);
            vis[i]=0;
        }
    }
}

void solve()
{
    cin>>n>>m;
    dfs(1,0);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}