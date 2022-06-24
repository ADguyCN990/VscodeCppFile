#include<bits/stdc++.h>
using namespace std;
#define MAXN 50005
#define MAXM 150005
int m;
int vis[MAXN],cnt[MAXN],dis[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}

int spfa(int s)
{
    queue <int> q;
    vis[s]=1;q.push(s);
    memset(dis,-0x3f,sizeof(dis));
    dis[s]=0;
    while(!q.empty())
    {
        int now=q.front();q.pop();vis[now]=0;
        for(int i=head[now];i!=-1;i=edge[i].next)
        {
            int to=edge[i].to;
            int val=edge[i].val;
            if(dis[to]<dis[now]+val)
            {
                dis[to]=dis[now]+val;
                if(!vis[to])
                {
                    vis[to]=1;
                    q.push(to);
                }
            }
        }
    }
    return dis[50001];
}

void solve()
{
    cin>>m;
    memset(head,-1,sizeof(head));
    //n 属于 [1,500001]
    for(int i=1;i<=50001;i++)
    {
        add_edge(i-1,i,0);
        add_edge(i,i-1,-1);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;a++;b++;
        add_edge(a-1,b,c);
    }
    cout<<spfa(0)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}