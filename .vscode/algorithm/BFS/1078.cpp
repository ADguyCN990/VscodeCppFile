#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
int mp[MAXN][MAXN];
pii path[MAXN][MAXN];
int n;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int vis[MAXN][MAXN];

void bfs()
{
    queue <pii> q;
    vis[n-1][n-1]=1;
    q.push({n-1,n-1});
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(vis[xx][yy]) continue;
            if(xx>=n||xx<0||yy>=n||yy<0) continue;
            if(mp[xx][yy]) continue;
            path[xx][yy]={x,y};
            vis[xx][yy]=1;
            q.push({xx,yy});

        }
    }
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mp[i][j];
    bfs();
    int i=0,j=0;
    while(i!=n-1||j!=n-1)
    {
        int x,y;
        cout<<i<<" "<<j<<endl;
        x=path[i][j].first;
        y=path[i][j].second;
        i=x,j=y;
    }
    cout<<n-1<<" "<<n-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}