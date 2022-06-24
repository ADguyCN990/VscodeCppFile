#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
int vis[MAXN];
int b[MAXN];
int n,cnt;

void dfs(int now)
{
    if(now>n)
    {
        cnt++;
        for(int i=1;i<=n;i++)
            cout<<b[i];
        cout<<endl;
        if(cnt==20)
            exit (0);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            b[now]=i;
            dfs(now+1);
            vis[i]=0;
        }
    }
}

void solve()
{
    cin>>n;
    dfs(1);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}