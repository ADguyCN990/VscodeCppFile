#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305
typedef pair<pair<int,int>,int> pii;
#define INF 0x3f3f3f3f
int n,m;
char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int sx,sy,ex,ey;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void get(char c,int &x,int &y)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==c&&(i!=x||j!=y))
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}

int bfs(int sx,int sy)
{
    queue <pii> q;
    q.push({{sx,sy},0});
    while(q.size())
    {
        int x=q.front().first.first,y=q.front().first.second,step=q.front().second;q.pop();
        char c=mp[x][y];
        if(c>='A'&&c<='Z')
        {
            get(c,x,y);
        }
        if(c=='=')
            return step;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(vis[a][b]) continue;
            if(a<1||a>n||b<1||b>m) continue;
            if(mp[a][b]=='#') continue;
            vis[a][b]=1;
            q.push({{a,b},step+1});   
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>mp[i]+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c=mp[i][j];
            if(c=='@')
            {
                sx=i,sy=j;
            }
            if(c=='=')
            {
                ex=i,ey=j;
            }
        }
    }
    cout<<bfs(sx,sy);
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}