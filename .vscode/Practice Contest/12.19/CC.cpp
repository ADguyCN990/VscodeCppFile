#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
#define MAXM 1005
#define mod 1000000007
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int g[MAXN][MAXN];
int indgr[MAXN][MAXN];//每个点能由多少个点转移过来
int outdgr[MAXN][MAXN];//每个点能转移多少个点
ll dp[MAXN][MAXN][4];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n,m;

void topu()
{
    queue <pii> q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(indgr[i][j]==0)
            {
                dp[i][j][1]=1;//入度为0的点设置初始状态
                q.push({i,j});
            }
        }
    }
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(a<1||a>n||b<1||b>m) continue;//越界
            if(g[a][b]!=g[x][y]+1) continue;//(a,b)不能由(x,y)转移而来
            dp[a][b][2]=(dp[a][b][2]+dp[x][y][1])%mod;//长度为2的由长度为1的转移而来
            dp[a][b][3]=(dp[a][b][3]+dp[x][y][2])%mod;//长度为3的由长度为2的转移而来
            dp[a][b][4]=(dp[a][b][4]+dp[x][y][3]+dp[x][y][4])%mod;//长度大于等于4的由长度为3和大于等于4的转移而来
            indgr[a][b]--;
            if(!indgr[a][b])
                q.push({a,b});
        }
    }
}

void solve()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            g[i][j]=read();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int a=i+dx[k],b=j+dy[k];
                if(a<1||a>n||b<1||b>m) continue;
                if(g[a][b]==g[i][j]+1)//(a,b)可以由(i,j)转移而来
                    indgr[a][b]++,outdgr[i][j]++;
            }
        }
    }
    topu();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!outdgr[i][j])
                ans=(ans+dp[i][j][4])%mod;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
    return 0;
}