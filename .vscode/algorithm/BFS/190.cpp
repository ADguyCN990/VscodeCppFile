#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,m;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
char s[MAXN][MAXN];
int dis[MAXN][MAXN];
bool ok(int x,int y)
{
    if(x>n||x<1||y>m||y<1) return false;
    return true;
}

int bfs(pii se)
{
    queue <pii> q;
    q.push(se);
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(!ok(xx,yy)) continue;
            if(dis[xx][yy]<=dis[x][y]+1) continue;
            if(s[xx][yy]=='*') continue;
            dis[xx][yy]=dis[x][y]+1;
            q.push({xx,yy});
            if(s[xx][yy]=='H')
                return dis[xx][yy];
        }
    }
}

void solve()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]+1;
    }
    pii se;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='K')
                se={i,j},dis[i][j]=0;
            else
                dis[i][j]=INF;
        }
    }
    cout<<bfs(se);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}