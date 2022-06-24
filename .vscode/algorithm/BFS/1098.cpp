#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
typedef pair<int,int> pii;
int n,m,cnt,ans;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int vis[MAXN][MAXN];
int mp[MAXN][MAXN];//放大小


void bfs(int x,int y)
{
    int num=0;
    vis[x][y]=cnt;
    queue <pii> q;
    q.push({x,y});
    while(q.size())
    {
        num++;
        int x=q.front().first,y=q.front().second;q.pop();
        int val=mp[x][y];
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(vis[xx][yy]!=0) continue;
            if(((val>>i)&1)) continue;
            if(xx>n||xx<1||yy>m||yy<1) continue;
            vis[xx][yy]=cnt;           
            q.push({xx,yy});
        }
    }
    ans=max(ans,num);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j])
            {
                cnt++;
                bfs(i,j);
            }
        }
    cout<<cnt<<endl;
    cout<<ans<<endl;
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}