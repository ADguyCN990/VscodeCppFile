#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005//点数
#define MAXM 500005//边数
#define X 114514
int n,m;//点和边的数量
//邻接表相关定义
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
//

//强连通分量相关定义
int low[MAXN],dfn[MAXN],key[MAXN],visit[MAXN];
stack <int> s;
int scc=0;//强连通分量个数
int num=0;//时间戳个数
struct node
{
    int mx;//集团中点权的最大值
    int sum;//缩点后的边权和
    //其他信息根据具体题目具体设置
}sccc[MAXN];//储存最后求出的各个强连通分量的信息

int siz[MAXN];//各个强连通分量包含点的个数，不一定需要
//

void init()
{
    tot=0;
    for(int i=0;i<=m;i++) head[i]=-1;
    scc=0;num=0;
    for(int i=1;i<=n;i++)
    {
        key[i]=i;
        dfn[i]=0;low[i]=0;visit[i]=0;
        //sccc[i].clear(); 要不要清除，怎么清除根据具体题目来
    }
}

void tarjan(int x)
{
    low[x]=dfn[x]=++num;//更新时间戳
    s.push(x);visit[x]=1;//入栈
    for(int i=head[x];i!=-1;i=edge[i].next)//遍历原始图
    {
        int y=edge[i].to;
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
    if(low[x]==dfn[x])//维护当前强连通分量
    {
        scc++;
        int now=-1;
        while(now!=x)
        {
            now=s.top();s.pop();
            visit[now]=0;//出栈标记
            //维护当前强连通分量内节点信息
            key[now]=scc;
            sccc[scc].mx=X;
            sccc[scc].sum=X;
        }
    }
}

void solve()
{
    init();
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
            tarjan(i);
    }
}