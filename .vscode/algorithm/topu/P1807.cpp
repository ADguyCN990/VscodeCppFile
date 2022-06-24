#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 50005
int head[MAXN];int tot;
struct node
{
    int to,next,val;
}edge[MAXN];
void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
#define INF -114514114514
int indgr[MAXN];ll dp[MAXN];//1到i的最长路
ll n,m;

void topp()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int next=edge[i].to;
            int val=edge[i].val;
            if(dp[now]+val>dp[next])
            {
                dp[next]=dp[now]+val;
            }
            indgr[next]--;
            if(indgr[next]==0) q.push(next);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        indgr[v]++;
    }
    for(int i=2;i<=n;i++) dp[i]=INF;
    topp();
    if(dp[n]==INF) cout<<-1<<endl;
    else cout<<dp[n]<<endl;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}