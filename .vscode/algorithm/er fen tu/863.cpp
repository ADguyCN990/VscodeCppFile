#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 100005
int n,nn,m;
int vis[MAXN],match[MAXN];
int ans=0;
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}

bool find(int now)
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])
        {
            vis[to]=1;
            if(match[to]==0||find(match[to]))
            {
                match[to]=now;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>nn>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}