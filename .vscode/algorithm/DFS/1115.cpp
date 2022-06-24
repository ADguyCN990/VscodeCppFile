#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int vis[MAXN][MAXN];
char mp[MAXN][MAXN];
int cnt=0;
int sx,sy;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||x>n||yy<1||yy>m) continue;
        if(vis[xx][yy]) continue;
        if(mp[xx][yy]=='#') continue;
        dfs(xx,yy);
    }
}

void init()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
}

void solve()
{
    init();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='@')
                sx=i,sy=j;
        }
    dfs(sx,sy);        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cnt+=vis[i][j];
    cout<<cnt<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>m>>n)
    {
        if(!n&&!m) break;
        solve();
    }
    return 0;
}