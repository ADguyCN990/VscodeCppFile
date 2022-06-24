#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define MAXM 200005
#define ll long long
ll dis[MAXN];//存储最短路
ll cnt[MAXN];//存储入队次数
ll n,m;
int visit[MAXN];
struct node
{
    int to,next,val;
}edge[MAXM];
int head[MAXM];
int tot=0;
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
void init()
{
    tot=0;
    for(int i=1;i<=n;i++)
    {
        visit[i]=0;
        head[i]=0;
        dis[i]=0x3f3f3f3f;
        cnt[i]=0;
    }
}

void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(w<0)
        {
            add_edge(u,v,w);
        }
        else 
        {
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
    }
}

bool spfa(int s,int n)//源点和节点个数
{
    dis[s]=0;
    queue <int> q;
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        int now=q.front();q.pop();
        visit[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int next=edge[i].to;
            int val=edge[i].val;
            if(dis[now]+val<dis[next])
            {
                dis[next]=dis[now]+val;               
                if(visit[next]==0)
                {
                    cnt[next]++;
                    if(cnt[next]>=n) return 0;
                    visit[next]=1;
                    q.push(next);
                }
            }
        }
    }
    return true;
}

void solve()
{
    cin>>n>>m;
    init();
    build();
    bool flag=spfa(1,n);
    if(flag==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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