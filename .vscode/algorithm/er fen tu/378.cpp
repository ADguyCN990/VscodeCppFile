#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 2005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,nn,m,ans;
int vis[MAXN],match[MAXN];

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
    memset(match,-1,sizeof(match));
    tot=0;
    ans=0;
    memset(head,0,sizeof(head));
}

bool find(int now)
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])
        {
            vis[to]=1;
            if(match[to]==-1||find(match[to]))
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
    init();
    for(int i=1;i<=m;i++)
    {
        int j,u,v;
        cin>>j>>u>>v;
        if(u==0||v==0) continue;//不用连边
        add_edge(u,v);
    }
    for(int i=1;i<n;i++)
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
    while(cin>>n)
    {
        if(!n) break;
        cin>>nn>>m;
        solve();
    }
    return 0;
}