#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
struct node
{
    int to,next;
}edge[MAXN];
int head[MAXN];int cnt;
void add_edge(int from,int to)
{
    edge[++cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}
ll dp[MAXN][2];//0表示参加，1表示不参加
ll n;
ll a[MAXN];
int visit[MAXN];
void dfs(int fa)
{
    dp[fa][0]=a[fa];
    dp[fa][1]=0;
    for(int i=head[fa];i;i=edge[i].next)
    {
        //cout<<"fa: "<<fa<<" son "<<edge[i].to<<endl;
        int son=edge[i].to;
        dfs(son);
        dp[fa][0]+=dp[son][1];
        dp[fa][1]+=max(dp[son][0],dp[son][1]);
    }
    return;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(v,u);
        visit[u]=1;
    }
    int rt;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            rt=i;
            dfs(i);
        }
    }
    cout<<max(dp[rt][0],dp[rt][1])<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i]<<" "<<i<<" attend: "<<dp[i][0]<<"not attend: "<<dp[i][1]<<endl;
    // }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}