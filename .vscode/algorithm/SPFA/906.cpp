#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 100005
#define INF 0x3f3f3f3f
ll dis[MAXN];
int vis[MAXN];
int head[MAXN];int cnt;
int num[MAXN];//统计入队次数
int n,m,mm;
struct node
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].next=head[from];head[from]=cnt;
}

void init()
{
    memset(head,0,sizeof(head));
    cnt=0;
}

int spfa()
{
    queue <int> q;
    memset(num,0,sizeof(num));
    memset(dis,0,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=1;
        q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                num[to]=num[now]+1;
                if(num[to]>=n) return 1;
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return 0;
}

void solve()
{
    cin>>n>>m>>mm;
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);add_edge(v,u,w);
    }
    for(int i=1;i<=mm;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,-w);
    }
    int ans=spfa();
    if(ans==1)
    {
        cout<<"YES"<<endl;
    } 
    else 
    {
        cout<<"NO"<<endl;
    }  
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