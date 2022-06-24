#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20005
#define MAXM 200005
int color[MAXN];
int n,m,ans;

int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

//如果边权小于mid就不用管，让他们待在一所监狱；否则就待在不同监狱

int dfs(int now,int c,int mid)
{
    color[now]=c;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        int val=edge[i].val;
        if(val<=mid) continue;
        if(color[to]==-1)
        {
            if(!dfs(to,!c,mid))
                return false;
        }
        else if(color[to]==color[now])
            return false;
    }
    return true;
}


bool check(int mid)
{
    for(int i=1;i<=n;i++)
        color[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
            if(!dfs(i,0,mid))
                return false;
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w),add_edge(v,u,w);
    }
    int l=0,r=1e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}