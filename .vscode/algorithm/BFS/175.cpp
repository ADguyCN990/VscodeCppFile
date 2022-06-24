#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
char s[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool ok(int x,int y)
{
    if(x>n||x<1||y>m||y<1) return false;
    return true;
}

void bfs()
{
    queue <pii> q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='1')
                q.push({i,j}),dis[i][j]=0;
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(!ok(xx,yy)) continue;
            if(dis[x][y]+1>=dis[xx][yy]) continue;
            dis[xx][yy]=dis[x][y]+1;
            q.push({xx,yy});
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i]+1;
    memset(dis,0x3f,sizeof dis);
    bfs();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}   

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}