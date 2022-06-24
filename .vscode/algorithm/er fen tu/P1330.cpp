#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005

int n,m;
int color[MAXN];
int sum0,sum1;

int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

bool dfs(int now,int c)
{
    color[now]=c;
    c==0?sum0++:sum1++;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(color[to]==-1)
        {
            if(!dfs(to,!c))
                return false;
        }
        else
        {
            if(color[to]==color[now])
                return false;
        }
    }
    return true;
}

void solve()
{
    memset(color,-1,sizeof(color));
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            sum0=0,sum1=0;
            if(!dfs(i,0))
            {
                cout<<"Impossible"<<endl;
                return;
            }
            else
                ans+=min(sum0,sum1);
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