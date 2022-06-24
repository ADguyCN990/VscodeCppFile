#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 500005
ll n,m;
ll value[MAXN];//存放每个原始点的点权
ll key[MAXN];//表示这个点位于哪个强联通分量
vector <int> original_mp[MAXN];//原始图，带环
vector <int> mp[MAXN];//缩点后的图
int indgr[MAXN];//缩点后的入度数
struct node
{
    ll mx;
    ll sum;
}sccc[MAXN];//强联通分量维护两个信息，整个强连通分量的最大值和缩点后的点权
stack <int> s;
int visit[MAXN];//标记是否在栈中
int dfn[MAXN];//第一次遍历得到的时间戳
int low[MAXN];//最小时间戳，用于判断是不是强连通分量的根
int num;//时间戳
int cnt;//强联通分量个数
ll dp[MAXN][2];//0表示到i点的最长路径之和，1表示路径上的最大点权

void tarjan(int x)
{
    num++;//时间加一
    dfn[x]=num;low[x]=num;//记录时间戳
    visit[x]=1;
    s.push(x);//入栈及标记
    for(auto j:original_mp[x])//遍历他的儿子们
    {
        if(dfn[j]==0) 
        {
            tarjan(j);//如果这个儿子的强联通分量没更新过，就更新一下，然后更新x的最小时间戳
            low[x]=min(low[j],low[x]);
        }
        else if(visit[j]==1)//如果已经遍历过了并且在栈中
        {
            low[x]=min(dfn[j],low[x]);
        }
    }
    if(dfn[x]==low[x])//当前这个点是强联通分量的根，那么就维护这个强联通分量
    {
        cnt++;
        int now=-1;
        while(x!=now)
        {
            now=s.top();s.pop();
            visit[now]=0;
            key[now]=cnt;
            sccc[cnt].mx=max(sccc[cnt].mx,value[now]);
            sccc[cnt].sum+=value[now];
        }
    }
}

void build()//缩点，建新图
{
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0) tarjan(i);
    }
    //先维护这张图的所有强连通分量
    //下面开始缩点
    for(int i=1;i<=n;i++)
    {
        for(auto j:original_mp[i])
        {
            if(key[i]==key[j])//原来边中的两个点同属于一个强连通分量，就不连边
            continue;
            //维护缩点后的新图
            mp[key[i]].emplace_back(key[j]);
            indgr[key[j]]++;
        }
    }
}

void topp()
{
    queue <int> q;
    for(int i=1;i<=cnt;i++)
    {
        dp[i][0]=sccc[i].sum;
        dp[i][1]=sccc[i].mx;
    }
    for(int i=1;i<=cnt;i++)
    {
        if(indgr[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto next:mp[now])//遍历图
        {
            if(dp[now][0]+sccc[next].sum>dp[next][0])//更新最大路径和
            {
                dp[next][0]=dp[now][0]+sccc[next].sum;
                dp[next][1]=max(sccc[next].mx,dp[now][1]);//更新最大值
            }
            else if(dp[now][0]+sccc[next].sum==dp[next][0])//如果有两条路径和最大的路径
            {
                //最大值选两者中最大的那个（相当于选择了那条路径）
                dp[next][1]=max(dp[now][1],dp[next][1]);
            }
            indgr[next]--;
            if(indgr[next]==0) q.push(next);
        }
    }
}

void output()
{
    int ans=1;
    for(int i=1;i<=cnt;i++)
    {
        if(dp[i][0]>dp[ans][0]||(dp[i][0]==dp[ans][0]&&dp[i][1]>dp[ans][1]))
        {
            ans=i;
        }
    }
    cout<<dp[ans][0]<<" "<<dp[ans][1]<<endl;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>value[i];
        key[i]=i;//初始化，类似于并查集
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        original_mp[u].emplace_back(v);
    }
    build();//缩点建新图
    topp();
    output();
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}