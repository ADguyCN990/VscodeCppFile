#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 505
#define INF 0x3f3f3f3f
ll ans=0x3f3f3f3f;
ll dis[MAXN];
ll n,m;
struct node
{
    ll to, next, val;
    
}edge[MAXM];
int head[MAXM],cnt;

void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

ll dij(int s)
{
    priority_queue <int> q;
    for(int i=1;i<=n;i++) dis[i]=INF;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int now=q.top();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            if(dis[to]>dis[now]+edge[i].val)
            {
                dis[to]=dis[now]+edge[i].val;
                q.push(to);
            }
        }
    }
    ll tmp=-1;
    for(int i=1;i<=n;i++)
    {
        tmp=max(tmp,dis[i]);
    }
    return tmp;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int from,to,val;
        cin>>from>>to>>val;
        add_edge(from,to,val);add_edge(to,from,val);
    }
    ans=dij(1);
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}