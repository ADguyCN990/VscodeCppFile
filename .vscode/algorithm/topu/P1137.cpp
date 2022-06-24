#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 200005
#define ll long long
ll n,m;
ll head[MAXM];int cnt=0;
ll indgr[MAXN];
ll dp[MAXN];
struct node
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}
void init()
{
    for(int i=1;i<=n;i++) 
    {
        dp[i]=0;
        indgr[i]=0;
    }
}
void build()
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        indgr[v]++;
    }
}
void topp()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(indgr[i]==0)
        {
            dp[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=head[now];i;i=edge[i].next)
        {
            int j=edge[i].to;
            dp[j]=max(dp[j],dp[now]+1);
            indgr[j]--;
            if(indgr[j]==0) q.push(j);
        }
    }
}
void output()
{
    for(int i=1;i<=n;i++) cout<<dp[i]<<endl;
}
void solve()
{
    cin>>n>>m;
    init();
    build();
    topp();
    output();
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}