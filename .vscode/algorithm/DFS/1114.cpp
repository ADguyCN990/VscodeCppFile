#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int n;
char mp[MAXN][MAXN];
typedef pair<int,int> pii;
int vis[MAXN][MAXN];
int sx,sy,ex,ey;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool dfs(int x,int y)
{
    vis[x][y]=1;
    if(x==ex&&y==ey) return true;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=n||xx<0||yy>=n||yy<0) continue;
        if(vis[xx][yy]) continue;
        if(mp[xx][yy]=='#') continue;
        if(dfs(xx,yy)) return true;
    }
    return false;
}

void solve()
{
    memset(vis,0,sizeof vis);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mp[i][j];

    cin>>sx>>sy>>ex>>ey;
    if(mp[sx][sy]=='#'||mp[ex][ey]=='#')
    {
        cout<<"NO"<<endl;
        return;
    }
    bool flag=dfs(sx,sy);
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}