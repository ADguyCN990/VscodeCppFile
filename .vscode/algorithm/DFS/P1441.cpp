#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define V 2000
int n,m;
int ans;
int a[MAXN];
int vis[MAXN];//1表示已删除

int dp[2005];//表示重量为i的方案是否可行，可行为1

void work()//对当前的状态进行DP处理，计算结果
{
    memset(dp,0,sizeof dp);
    int cnt=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;//这个数是被删除的，不用管
        for(int j=V-a[i];j>=0;j--)
        {   
            if(dp[j])
                dp[j+a[i]]=1;
        }
    }
    for(int i=1;i<=V;i++)
        cnt+=dp[i];
    ans=max(ans,cnt);
}

void dfs(int now,int cnt)//目前正在遍历的数，已经删除的个数
{
    if(cnt>m) return;//可行性剪枝
    if(now==n+1) 
    {
        if(cnt==m)
        work();
        return;
    }
    //两种方案，选m个删除，选n-m个保留，第一种状态较少，选择该方案，优化搜索顺序
    vis[now]=1;
    dfs(now+1,cnt+1);//删除这个数
    vis[now]=0;//恢复现场
    dfs(now+1,cnt);//不删除该数字

}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}