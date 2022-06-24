#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM MAXN*MAXN
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
int low[MAXN],dfn[MAXN],vis[MAXN],key[MAXN],sccc,num;//sccc为强联通分量个数，num为时间戳
int head[MAXN];int tot;
int indgr[MAXN],oudgr[MAXN];
stack <int> st;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
void tarjan(int x)
{
    low[x]=dfn[x]=++num;
    st.push(x);vis[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].to;
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(vis[y])//在栈中
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x])
    {
        sccc++;
        int now=-1;
        while(now!=x)
        {
            now=st.top();st.pop();
            vis[now]=0;//出栈标记
            key[now]=sccc;
        }
    }

}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        key[i]=i;
    for(int i=1;i<=n;i++)
    {
        int j;
        while(cin>>j)
        {
            if(!j) break;
            add_edge(i,j);
        }
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int now=1;now<=n;now++)
    {
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(key[now]==key[to]) continue;
            indgr[key[to]]++;oudgr[key[now]]++;
        }
    }
    int cnts=0;int cnte=0;
    for(int i=1;i<=sccc;i++)
    {
        if(!indgr[i]) 
            cnts++;
        if(!oudgr[i]) 
            cnte++;
    }
    cout<<cnts<<endl;
    if(sccc==1)
        cout<<0<<endl;
    else    
        cout<<max(cnts,cnte)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}