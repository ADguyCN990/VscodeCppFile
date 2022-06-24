#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 20005
int n,m,k,ans;
int mp[105][105];
int vis[MAXN][MAXN];
pair <int,int> match[MAXN][MAXN];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool ok(int x,int y)
{
    if(x>n||x<1||y>m||y<1) return false;
    return true;
}

bool find(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(!ok(xx,yy)) continue;
        if(mp[xx][yy]) continue;
        if(!vis[xx][yy])
        {
            vis[xx][yy]=1;
            int xxx=match[xx][yy].first;
            int yyy=match[xx][yy].second;
            if(xxx==0||yyy==0||find(xxx,yyy))
            {
                match[xx][yy]={x,y};
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]=1;
    }
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]||((i+j)&1)) continue;
            memset(vis,0,sizeof(vis));
            if(find(i,j))
                ans++;
        }
    }
    cout<<n*m-k-ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}