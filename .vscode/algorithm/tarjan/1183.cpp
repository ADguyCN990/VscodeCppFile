#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 30005
int n,m,num,cnt,ans,root;
int low[MAXN],dfn[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(head,-1,sizeof(head));
    tot=0,num=0,ans=0,cnt=0;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    int cnt=0;//删除该点，原先的一个连通块变成cnt个连通块
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
            if(low[y]>=dfn[x]) cnt++;//x是割点，并且对于y，删除x后y不能与其祖先节点相连，多一个连通块
        }
        else low[x]=min(low[x],dfn[y]);
    }
    if(x!=root) cnt++;//x不是根节点的话祖先也得分出来一块
    ans=max(ans,cnt);
}

void solve()
{
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    for(int i=0;i<n;i++)
    {
        if(!dfn[i])
        {
            root=i;
            cnt++;//连通块数量加一
            tarjan(i);//以i为根节点去遍历
        }
    }
    cout<<ans+cnt-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        solve();
    }
    return 0;
}