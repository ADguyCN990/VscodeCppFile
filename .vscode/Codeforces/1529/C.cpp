#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n;
ll L[MAXN];ll R[MAXN];
ll dp[2][MAXN];//这个点选最小值或最大值的最优解
vector<int> near[MAXN];//邻接表存图

void dfs(int u,int father)//father为他的父节点
{
    dp[0][u]=0;dp[1][u]=0;//状态清零
    for(auto v:near[u])
    {
        if(father==v) continue;//遇到了他的父节点，跳过
        dfs(v,u);
        dp[0][u]+=max(abs(L[u]-R[v])+dp[1][v],abs(L[u]-L[v])+dp[0][v]);//v选择了最小值，他的儿子选最小值或最大值
        dp[1][u]+=max(abs(R[u]-R[v])+dp[1][v],abs(R[u]-L[v])+dp[0][v]);
    }
}

void solve()//近乎于树形DP板子题
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>L[i]>>R[i];
    for(int i=1;i<=n;i++) near[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        near[x].emplace_back(y);near[y].emplace_back(x);
    }  
    dfs(1,-1);//无根树，取一个不存在的值作为假想的根
    cout<<max(dp[0][1],dp[1][1])<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}