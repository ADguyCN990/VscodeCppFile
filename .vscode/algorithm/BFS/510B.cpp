#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
int n,m;
int cnt;
int mp[MAXN][MAXN];
char ttt[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int x,int y,int px,int py,int sx,int sy)
{
    cnt++;
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a==px&&b==py) continue;
        if(vis[a][b]&&cnt>=4&&mp[a][b]==mp[sx][sy]) 
        {
            cout<<"Yes"<<endl;
            exit (0);
        }
        if(a<1||a>n||b<1||b>m) continue;
        if(vis[a][b]) continue;
        if(mp[a][b]!=mp[sx][sy]) continue;
        vis[a][b]=1;
        //cnt++;
        dfs(a,b,x,y,sx,sy);
        cnt--;
        //vis[a][b]=0;
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>ttt[i]+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mp[i][j]=ttt[i][j]-'A'+1;
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j])
            {
                vis[i][j]=1;
                cnt=0;
                dfs(i,j,-1,-1,i,j);
            }
        }
    }

    cout<<"No"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}