#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MAXM 5005
#define exp 1e-4
int h[MAXN];int tot;
double dis[MAXN];
struct node
{
    int to,next;
    double val;
}e[MAXM];

void add_edge(int from,int to,double val)
{
    e[++tot].to=to;e[tot].val=val;e[tot].next=h[from];h[from]=tot;
}

double f[MAXN];//点权
int n,m;
int vis[MAXN];
int cnt[MAXN];
bool check(double mid)//假设答案为mid
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=1;
        cnt[i]=0;
        q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=h[now];i;i=e[i].next)
        {
            int to=e[i].to;
            double val=e[i].val*mid-f[now];
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n)//存在负环
                    return true;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to]=1;
                }
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        double w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    double l=0.0;double r=1000.0;
    double ans;
    while(r-l>=exp)
    {
        double mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else
            r=mid;
    }
    printf("%.2lf\n",ans);
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}