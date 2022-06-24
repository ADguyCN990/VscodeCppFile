#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
#define MAXM 100005
#define INF 0x3f3f3f3f
ll n,m,s,e;
ll dis[MAXN];
struct node
{
    ll to, next, val;
    bool operator <  (const node &a) {return val>a.val;}
}edge[MAXM];
int head[MAXM],cnt;

void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void dij(int s)
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
}

void solve()
{
    cin>>n>>m>>s>>e;
    for(int i=1;i<=m;i++)
    {
        int to,from,val;
        cin>>from>>to>>val;
        add_edge(from,to,val);
        add_edge(to,from,val);
    }
    dij(s);
    cout<<dis[e]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}