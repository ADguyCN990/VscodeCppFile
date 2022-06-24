#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
#define MAXM 1000005
#define MAXK 25
ll dp[MAXN][MAXN][MAXK];
int cnt=0;
int head[MAXM];
int mp[MAXN][MAXN];//将二维的点降到一维进行处理
ll n,m,k;
struct node
{
    int from;int next;int to;int val;
}edge[MAXM];
void add_edge(int from,int to,int val)
{
    edge[++cnt].to=to;edge[cnt].val=val;edge[cnt].from=from;edge[cnt].next=head[from];head[from]=cnt;
}

int get(int x,int y){return (x-1)*m+y;}
void pre()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            mp[i][j]=(i-1)*m+j;
            dp[i][j][0]=0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int l=1;l<=k;l++)
                dp[i][j][l]=1000000007;
}
void input()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int temp;
            cin>>temp;
            int u=mp[i][j];int v=mp[i][j+1];
            add_edge(u,v,temp);add_edge(v,u,temp);
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int temp;
            cin>>temp;
            int u=mp[i][j];int v=mp[i+1][j];
            add_edge(u,v,temp);add_edge(v,u,temp);
        }
    }
}

void output()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j][k/2]*2<<" ";
        }
        cout<<endl;
    }
}

void solve()
{
    cin>>n>>m>>k;
    pre();
    input();
    if(k%2==1)//特判,不可能存在奇数步的情况
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //dp[l][r][k]=min(dp[l-1][r][k-1]+w1,dp[l+1][r][k-1]+w2,dp[l][r-1][k-1]+w3,dp[l][r+1][k-1]+w4)
    for(int K=1;K<=k/2;K++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int now=mp[i][j];
                for(int t=head[now];t;t=edge[t].next)
                {
                    //cout<<edge[t].from<<" "<<edge[t].to<<" "<<edge[t].val<<endl;
                    int nxt=edge[t].to;
                    int nxt_x=(nxt-1)/m+1;
                    int nxt_y=(nxt-1)%m+1;
                    //cout<<nxt_x<<" "<<nxt_y<<endl;
                    dp[i][j][K]=min(dp[i][j][K],dp[nxt_x][nxt_y][K-1]+edge[t].val);
                    
                }
            }
        }
    }
    output();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}