#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;//一共有n个点
//强连通分量相关定义

int dfn[MAXN],low[MAXN];//时间戳以及回溯值（最小时间戳）
vector <int> sccc[MAXN];//储存最后求出的各个强连通分量的信息
int key[MAXN];//key[i]表示i在编号为key[i]的强连通分量中
int num=0;//时间戳
int scc=0;//强连通分量个数
stack <int> s;
int visit[MAXN];//记录是否在栈中

//

vector <int> original_mp[MAXN];//原始图

void tarjan(int x)
{
    low[x]=dfn[x]=++num;
    s.push(x);visit[x]=1;
    for(auto y:original_mp[x])//遍历原始图
    {
        if(dfn[y]==0)
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(visit[y]==1)
        {
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x])
    {
        scc++;
        int now=-1;
        while(x!=now)
        {
            now=s.top();s.pop();
            visit[now]=0;
            key[now]=scc;
            sccc[scc].emplace_back(now);
        }
    }
}

void init()
{
    scc=0;num=0;
    for(int i=1;i<=n;i++)
    {
        key[i]=i;
        dfn[i]=0;low[i]=0;sccc[i].clear();visit[i]=0;
    }
}

void solve()
{
    init();
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)//如果当前点没被遍历过，跑一遍Tarjan
            tarjan(i);
    }
}

