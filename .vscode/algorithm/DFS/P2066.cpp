#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
int n,m;
int mp[MAXN][MAXN];
int ans=0;
int tmp[MAXN];
int path[MAXN];
void dfs(int now,int num,int val)//当前分配完的子公司，当前已经分配完的机器，当前的和
{
    if(now==n&&num==m)
    {
        if(val>ans)
        {
            ans=val;
            for(int i=1;i<=n;i++)
                path[i]=tmp[i];
        }
        return;
    }
    if(now>n) return;
    if(num>m) return;
    if(now==n&&num<m) return;

    for(int i=0;i<=m;i++)
    {
        tmp[now+1]=i;

        dfs(now+1,num+i,val+mp[now+1][i]);
        tmp[now+1]=0;
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    dfs(0,0,0);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<path[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}