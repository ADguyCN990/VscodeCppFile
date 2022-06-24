#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 2000005
#define INF 0x3f3f3f3f
ll n,m;
int head[MAXM];int rhead[MAXM];int cnt;
struct node
{
    int to,next;
}edge[MAXM];
void add_edge(int *h,int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=h[from];h[from]=cnt;
}
int vis[MAXN];
ll a[MAXN];
ll dmin[MAXN];ll dmax[MAXN];

void spfa(ll *dis,int s,int *h,int flag)
{
    memset(vis,0,sizeof(vis));
    if(flag==0) 
    {
        memset(dmin,INF,sizeof(dmin));
    }
    
    queue <int> q;
    q.push(s);vis[s]=1;dis[s]=a[s];
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"min: "<<dmin[i]<<" dmax: "<<dmax[i]<<endl;
    //     //ans=max(ans,dmax[i]-dmin[i]);
    // }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=h[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(flag==0&&dis[to]>min(dis[now],a[to])||flag==1&&dis[to]<max(dis[now],a[to]))
            {
                if(flag==0)
                    dis[to]=min(dis[now],a[to]);
                else if(flag==1)
                    dis[to]=max(dis[now],a[to]);
                if(vis[to]==0)
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
   
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int from,to,f;
        cin>>from>>to>>f;
        add_edge(head,from,to);add_edge(rhead,to,from);
        if(f==2)
        {
            add_edge(head,to,from);
            add_edge(rhead,from,to);
        }
            
    }
    spfa(dmin,1,head,0);
    spfa(dmax,n,rhead,1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<"min: "<<dmin[i]<<" dmax: "<<dmax[i]<<endl;
        ans=max(ans,dmax[i]-dmin[i]);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}