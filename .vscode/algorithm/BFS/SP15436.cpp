#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 255
typedef pair<int,int> pii;
int n,m;
int mp[MAXN][MAXN];
int vis[MAXN][MAXN];
map <int,int> num;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int bfs(int x,int y)
{
    vis[x][y]=1;
    int cnt=0;
    queue <pii> q;
    q.push({x,y});
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        cnt++;
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];
            if(vis[a][b]) continue;
            if(mp[a][b]==0) continue;
            if(a<1||a>n||b<1||b>m) continue;
            q.push({a,b});
            vis[a][b]=1;
        }
    }
    cout<<cnt<<endl;
    return cnt;
}

void solve()
{
    memset(vis,0,sizeof vis);
    num.clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    int ans=0;
    set <int> s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]&&!vis[i][j])
            {
                ans++;
                int cnt=bfs(i,j);
                s.insert(cnt);
                num[cnt]++;
            }
        }
    }
    cout<<ans<<endl;
    for(auto it:s)
    {
        cout<<it<<" "<<num[it]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)
    {
        if(!n&&!m) break;
        solve();
    }
    return 0;
}