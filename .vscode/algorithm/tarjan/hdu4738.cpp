#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 2*1005*1005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m,root;
int ans;
int num,dcc,dfn[MAXN],low[MAXN],key[MAXN],bridge[MAXM],vis[MAXN];
stack <int> st;

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

void init()
{
    memset(head,0,sizeof(head));
    tot=0;
    ans=INF;
    memset(bridge,0,sizeof(bridge));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
}

int get(int x)
{
    if(x&1) return x+1;
    else return x-1;
}

void tarjan(int x,int pre)
{
    dfn[x]=low[x]=++num;
    st.push(x);vis[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y,i);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x])
            {
                bridge[i]=bridge[get(i)]=1;
            }
        }
        else if(i!=get(pre))
            low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x])
    {
        dcc++;
        int now=-1;
        while(now!=x)
        {
            now=st.top();st.pop();vis[now]=0;
            key[now]=dcc;
        }
    }
}

void solve()
{
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w),add_edge(v,u,w);
    }
    tarjan(1,0);
    int flag=1;//整个图是不是连通图
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            flag=0;
            break;
        }
    }
    if(!flag)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=tot;i++)
    {
        if(bridge[i])
            ans=min(ans,edge[i].val);
    }
    if(ans==INF)//整张图没有桥
        cout<<-1<<endl;
    else if(ans==0)//权值为0也要派一个人去炸
        cout<<1<<endl;
    else
        cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)
    {
        if(!n&&!m) break;
        solve();
    }
    return 0;
}