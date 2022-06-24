#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 400005
#define INF 0x3f3f3f3f
int n,m,res;
int dfn[MAXN],low[MAXN],num;
int d[MAXN],sub[MAXN],csum,cnt;
ll ans,sum;

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

int get(int x)
{
    if (x&1) return x+1;
    else return x-1;
}

void tarjan(int now,int pre)
{
    dfn[now]=low[now]=++num;
    sub[now]=d[now];
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!dfn[to])
        {
            tarjan(to,i);
            sub[now]+=sub[to];
            if(dfn[now]<low[to])
            {
                if(!(((sub[to] - 1) / 2) & 1))
                        res = min(res,edge[i].val);
            }
            else
                res=min(res,edge[i].val);
            low[now]=min(low[now],low[to]);
        }
        else if(i!=get(pre))
        {   
            res=min(res,edge[i].val);
            low[now]=min(low[now],dfn[to]);
        }
        if(dfn[to]>dfn[now])
        {
            sum+=edge[i].val;
            csum++;
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w),add_edge(v,u,w);
        d[u]++,d[v]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            res=INF;sum=0;
            tarjan(i,0);
            if(csum&1) ans+=(sum-res);
            else ans+=sum;
        }  
    }    
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}