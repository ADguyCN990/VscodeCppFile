#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int n;
int vis[MAXN],path[MAXN];

bool dfs(int now,int mx)//当前深度与最大深度
{
    if(now>mx) return false;//可行性剪枝
    if(path[now-1]==n&&now==mx) return true;
    memset(vis,0,sizeof vis);
    vis[1]=1;
    for(int i=now-1;i;i--)
    {
        for(int j=i;j;j--)
        {
            int sum=path[i]+path[j];
            if(vis[sum]) continue;//可行性剪枝
            if(sum<=path[now-1]) continue;//可行性剪枝，严格递增序列
            if(sum>n) continue;//可行性剪枝，严格递增序列
            vis[sum]=1;
            path[now]=sum;
            if(dfs(now+1,mx)) return true;
            path[now]=0;
        }
    }
    return false;
}

void solve()
{
    
    int depth=2;
    path[1]=1;//哨兵
    while(!dfs(2,depth)) depth++;//迭代加深
    for(int i=1;i<depth;i++) cout<<path[i]<<" ";
    cout<<endl;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n&&n)
    {
        solve();
    }
    
    return 0;
}