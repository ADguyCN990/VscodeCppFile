#include<bits/stdc++.h>
using namespace std;
#define MAXM 200005
#define MAXN 505
int n,m;
int dfn[MAXN],low[MAXN],key[MAXN],scc,num;
int vis[MAXN];stack <int> st;

int head[MAXN],h[MAXN],tot;
struct node
{
    int to,next;
}edge[MAXM];
void add(int h[],int from,int to)
{
    edge[++tot].to=to;edge[tot].next=h[from];h[from]=tot;
}
int indgr[MAXN],ans[MAXN];

void tarjan(int x)
{
    low[x]=dfn[x]=++num;
    st.push(x);vis[x]=1;
    for(int i=h[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y]==1)
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(low[x]==dfn[x])
    {
        scc++;
        int now=-1;
        while(now!=x)
        {
            now=st.top();st.pop();
            vis[now]=0;
            key[now]=scc;
        }
    }
}

void topu()
{
    memset(ans,0x3f,sizeof ans);
    queue <int> q;
    q.push(key[1]);
    ans[key[1]]=0;
    while(q.size())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            indgr[to]--;
            ans[to]=min(ans[to],ans[now]+1);

            if(!indgr[to]) q.push(to);
        }
    }
}

void work()
{
    for(int now=1;now<=n;now++)
    {
        for(int i=h[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(key[now]==key[to]) continue;
            add(head,key[now],key[to]);
            indgr[key[to]]++;
        }
    }
}

void solve()
{
    scanf("%d%d",&n,&m);
    //for(int i=1;i<=n;i++) key[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(h,u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    //for(int i=1;i<=n;i++) cout<<key[i]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            printf("-1\n");
            return;
        }
    }
    work();
    topu();
    for(int i=1;i<=n;i++)
    {
        if(indgr[key[i]])
        {
            printf("-1\n");
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1) printf("%d",ans[key[i]]);
        else printf(" %d",ans[key[i]]);
    }
    //cout<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}