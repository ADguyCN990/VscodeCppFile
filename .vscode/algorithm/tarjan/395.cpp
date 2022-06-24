#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int num,dfn[MAXN],low[MAXN],dcc,indgr[MAXN],key[MAXN],vis[MAXN];
stack <int> st;

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int bridge[MAXM];//判断某条边是不是桥
int get(int x)//根据边的编号求它的反向边
{
    if(x&1) return x+1;
    return x-1;
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
            tarjan(y,i);//是从i这一条边遍历过来的
            low[x]=min(low[x],low[y]);
            if(dfn[x]<low[y])//y无论如何都回不到y的祖先节点，那么这条边和其反向边为桥
            {
                bridge[i]=bridge[get(i)]=1;
            }
        }
        else if(i!=get(pre))//这条边不是走回头路的，且y之前已经记录过它的时间戳
        {
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x])
    {
        dcc++;
        int now=-1;
        while(now!=x)
        {
            now=st.top();st.pop();
            vis[now]=0;
            key[now]=dcc;
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    tarjan(1,0);
    for(int i=1;i<=tot;i++)
        if(bridge[i])
            indgr[key[edge[i].to]]++;
    int ans=0;
    for(int i=1;i<=dcc;i++)
        if(indgr[i]==1)
            ans++;
    cout<<(ans+1)/2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}