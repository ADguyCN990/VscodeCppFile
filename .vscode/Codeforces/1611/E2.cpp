#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
#define INF 0x3f3f3f3f
typedef pair<int,int> pii;
int n,k,ans;
int d[MAXN],a[MAXN];
int dis1[MAXN],dis2[MAXN];

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
    tot=0;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        head[i]=0;
        dis1[i]=INF;
        dis2[i]=INF;
        d[i]=0;
    }
}

void bfs()
{
    queue <int> q;
    q.push(1);
    dis1[1]=0;
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis1[to]>dis1[now]+1)
            {
                dis1[to]=dis1[now]+1;
                q.push(to);
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        dis2[a[i]]=0;
        q.push(a[i]);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis2[to]>dis2[now]+1)
            {
                dis2[to]=dis2[now]+1;
                q.push(to);
            }
        }
    }
}

int dfs(int now,int pre)
{
    int ans=0;
    if(dis1[now]>=dis2[now])
        return 1;
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(to==pre) continue;
        ans+=dfs(to,now);
    }
    return ans;
}

void solve()
{
    cin>>n>>k;
    init();
    for(int i=1;i<=k;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
        d[u]++,d[v]++;
    }
    bfs();
    for(int i=2;i<=n;i++)
    {
        if(d[i]==1&&dis1[i]<dis2[i])//特判叶子节点的最短路
        {
            cout<<-1<<endl;
            return;
        }
    }
    //已经保证了不失误的情况下不能从根节点逃到叶子节点。只要在某条路上，某个人能拦截时就去拦截他，这条路就废了。
    cout<<dfs(1,-1)<<endl;
    //cout<<d[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}
