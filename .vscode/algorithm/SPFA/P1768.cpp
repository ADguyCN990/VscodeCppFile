#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 7005
#define MAXM 20005
#define ll long long
#define exp 1e-4
int n,m;
int vis[MAXN],cnt[MAXN];
double dis[MAXN];
int h[MAXN];int tot;
struct node
{
    int to,next;
    double v,p;
}e[MAXM];
void add_edge(int from,int to,double v,double p)
{
    e[++tot].to=to;e[tot].v=v;e[tot].p=p;e[tot].next=h[from];h[from]=tot;
}

bool check(double mid)
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        dis[i]=0;vis[i]=1;cnt[i]=0;
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=h[now];i;i=e[i].next)
        {
            int to=e[i].to;
            double val=e[i].p*mid-e[i].v;
            if(dis[to]>dis[now]+val)
            {
                dis[to]=dis[now]+val;
                cnt[to]=cnt[now]+1;
                if(cnt[to]>=n) 
                    return true;
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        double v,p;
        cin>>a>>b>>v>>p;
        add_edge(a,b,v,p);
    }
    double l=0.0;double r=1000.0;double ans=-1;
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
    printf("%.1lf\n",ans);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}