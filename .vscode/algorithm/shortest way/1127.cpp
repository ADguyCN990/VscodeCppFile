#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 3005
#define INF 0x3f3f3f3f
ll n,m,p;
ll dis[MAXN];
int num[MAXN];
struct node
{
    ll to, next, val;
    
}edge[MAXM];
int head[MAXM],cnt;
int vis[MAXN];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}
ll ans=0x3f3f3f3f;
ll dij(int s)
{
    priority_queue <pair<int,int>> q;
    for(int i=1;i<=p;i++) dis[i]=INF;
    for(int i=1;i<=p;i++) vis[i]=0;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        pair<int,int> temp=q.top();q.pop();
        int now=temp.second;
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]>dis[now]+edge[i].val)
            {
                dis[to]=dis[now]+edge[i].val;
                q.push({-dis[to],to});
            }
        }
    }
    ll tmp=0;
    for(int i=1;i<=p;i++) tmp+=dis[i]*num[i];
    return tmp;
}

void solve()
{
    cin>>n>>p>>m;

    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        num[tmp]++;
    }
    for(int i=1;i<=m;i++)
    {
        int to,from,val;
        cin>>from>>to>>val;
        add_edge(from,to,val);
        add_edge(to,from,val);
    }
    for(int i=1;i<=p;i++) 
    {
        ans=min(ans,dij(i));
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}