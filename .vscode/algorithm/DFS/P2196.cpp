#include<bits/stdc++.h>
using namespace std;
#define MAXN 25
int a[MAXN];
int path[MAXN];
int vis[MAXN];
int n,ans;
vector <int> mp[MAXN];
int tmp[MAXN];
void dfs(int now,int pre,int sum,int len)
{
    if(len>n) return;//可行性剪枝

    if(mp[now].size()==0&&sum>ans)
    {
        memset(path,0,sizeof path);
        for(int i=1;i<=len;i++) path[i]=tmp[i];
        ans=sum;
        // cout<<ans<<endl;
        // for(int i=1;i<=len;i++) cout<<path[i]<<" ";
        // cout<<endl;
        return;
    }
    for(int j=0;j<mp[now].size();j++)
    {
        int to=mp[now][j];
        if(to==pre) continue;
        if(vis[to]) continue;
        vis[to]=1;
        tmp[len+1]=to;
        dfs(to,now,sum+a[to],len+1);
        vis[to]=0;
        tmp[len+1]=0;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int t;
            cin>>t;
            if(t)
                mp[i].emplace_back(j);
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto x:mp[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }    
        
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        vis[i]=1;
        tmp[1]=i;
        dfs(i,-1,a[i],1);
    }
    for(int i=1;path[i];i++) cout<<path[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}