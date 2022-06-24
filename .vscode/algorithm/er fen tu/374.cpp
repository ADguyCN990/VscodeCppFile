#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM MAXN+MAXN
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,k,m,ans;
int mp[105][105];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool ok(int x,int y)
{
    if(x>n||x<1||y>n||y<1) return false;
    return true;
}
int vis[MAXN];int match[MAXN];
int head[MAXN];int tot;
struct EDGE
{
    int to,next;
}edge[MAXM];
void add_edge(int from,int to)
{
    edge[++tot].to=to;edge[tot].next=head[from];head[from]=tot;
}
int get(int x,int y)
{
    return (x-1)*n+y;
}

bool find(int now)
{
    for(int i=head[now];i;i=edge[i].next)
    {
        int to=edge[i].to;
        if(!vis[to])
        {
            vis[to]=1;
            if(match[to]==0||find(match[to]))
            {
                match[to]=now;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)&1||mp[i][j]) continue;
            for(int o=0;o<4;o++)
            {
                int x=i+dx[o];int y=j+dy[o];
                if(ok(x,y)&&!mp[x][y])
                    add_edge(get(i,j),get(x,y));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)&1) continue;
            memset(vis,0,sizeof(vis));
            if(find(get(i,j)))
                ans++;
        }
    }
    cout<<ans<<endl;
}   

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}