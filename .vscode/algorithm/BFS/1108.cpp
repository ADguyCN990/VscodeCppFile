#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int mp[MAXN][MAXN],vis[MAXN][MAXN];
int n;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int sum1,sum2;//山峰和山谷个数

void bfs(int x,int y)
{
    vis[x][y]=1;
    int f1=1;//是否有可能成为山峰
    int f2=1;//是否有可能成为山谷
    queue <pii> q;
    q.push({x,y});
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<8;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            
            if(xx>n||xx<1||yy>n||yy<1) continue;
            if(mp[xx][yy]>mp[x][y])//不可能成为山峰了
            {
                f1=0;
                continue;
            }
            if(mp[xx][yy]<mp[x][y])//不可能成为山谷了
            {
                f2=0;
                continue;
            }
            if(vis[xx][yy]) continue;
            if(mp[xx][yy]==mp[x][y])
            {
                vis[xx][yy]=1;
                q.push({xx,yy});
            }
            
        }
    }
    if(f1) 
    {
        sum1++;
        //cout<<"top: "<<x<<" "<<y<<endl;
    }
    if(f2) 
    {
        sum2++;
        //cout<<"bottom: "<<x<<" "<<y<<endl;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!vis[i][j])
                bfs(i,j);
    cout<<sum1<<" "<<sum2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}