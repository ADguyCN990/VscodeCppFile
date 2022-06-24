#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 200005
#define ll long long

ll n,m;

struct EDGE
{
    int to,next;
    bool same;//记录该边是否允许两边相等
}edge[MAXM];
int head[MAXN],hh[MAXN],tot;

void add_edge(int h[],int from,int to,bool same)
{
    tot++;edge[tot].to=to;edge[tot].next=h[from];h[from]=tot;
    edge[tot].same=same;
}

struct relation
{
    int f;int a;int b;
}relation[MAXM];

int scc;//强连通分量个数
int num;//时间戳
int vis[MAXN],low[MAXN],dfn[MAXN],key[MAXN];
stack <int> st;
struct node
{
    ll size=0;//糖果相同的人的数量
    ll candy=0;//糖果的数量
}sccc[MAXN];
int indgr[MAXN];
void tarjan(int x)
{
    num++;
    low[x]=num;dfn[x]=num;
    st.push(x);vis[x]=1;
    for(int i=hh[x];i;i=edge[i].next)
    {
        int j=edge[i].to;
        if(dfn[j]==0)
        {
            tarjan(j);
            low[x]=min(low[x],low[j]);
        }
        else if(vis[j]==1)
        {
            low[x]=min(low[x],dfn[j]);
        }
    }
    if(low[x]==dfn[x])
    {
        int now=-1;
        scc++;
        while(now!=x)
        {
            now=st.top();st.pop();
            sccc[scc].size++;
            key[now]=scc;
            vis[now]=0;       
        }
    }
}

void build()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=hh[i];j;j=edge[j].next)
        {
            int jj=edge[j].to;
            if(key[i]==key[jj]) continue;
            add_edge(head,key[i],key[jj],true);
            indgr[key[jj]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(relation[i].f==2)
        {
            if(key[relation[i].a]==key[relation[i].b])//之前已经定义为糖果相同，现在又要求糖果不同
            {
                cout<<-1<<endl;
                exit (0);
            }
            add_edge(head,key[relation[i].a],key[relation[i].b],false);
            indgr[key[relation[i].b]]++;
        }
        else if(relation[i].f==4)
        {
            if(key[relation[i].a]==key[relation[i].b])//之前已经定义为糖果相同，现在又要求糖果不同
            {
                cout<<-1<<endl;
                exit (0);
            }
            add_edge(head,key[relation[i].b],key[relation[i].a],false);
            indgr[key[relation[i].a]]++;
        }
    }
}

void topp()
{
    queue <int> q;
    for(int i=1;i<=scc;i++)
    {
        if(indgr[i]==0)
        {
            sccc[i].candy=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int j=edge[i].to;
            if(edge[i].same==true)//允许两边糖果数量相等
            {
                sccc[j].candy=max(sccc[j].candy,sccc[now].candy);
            }
            else if(edge[i].same==false)//不允许两个强连通分量糖果相等
            {
                sccc[j].candy=max(sccc[now].candy+1,sccc[j].candy);
            }
            indgr[j]--;
            if(indgr[j]==0) q.push(j);
        }
    }
    for(int i=1;i<=scc;i++)
    {
        if(indgr[i]!=0)//出现了自环
        {
            cout<<-1<<endl;
            exit (0);
        }
    }
}

void output()
{
    ll ans=0;
    for(int i=1;i<=scc;i++) 
    {
        ans=ans+sccc[i].candy*sccc[i].size;
    }
    if(!ans)
        cout<<-1<<endl;
    cout<<ans<<endl;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>relation[i].f>>relation[i].a>>relation[i].b;
        if(relation[i].f==1)//将所有权值相同的点缩成一点
        {
            add_edge(hh,relation[i].a,relation[i].b,true);
            add_edge(hh,relation[i].b,relation[i].a,true);
        }
        else if(relation[i].f==3)
        {
            add_edge(hh,relation[i].b,relation[i].a,true);
        }
        else if(relation[i].f==5)
        {
            add_edge(hh,relation[i].a,relation[i].b,true);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0) tarjan(i);
    }
    build();
    topp();
    output();
}   

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}